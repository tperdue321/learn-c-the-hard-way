#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100
#define NUM_OF_DB 1
#define TRUE 1
#define FALSE 0

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void die(const char *message) {
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

void address_print(struct Address *addr) {
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void database_load(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), NUM_OF_DB, conn->file);
  if (rc != 1)
    die("failed to load database");
}

struct Connection * database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
    die("Memory error");

  conn->db = malloc(sizeof(struct Database));
  if(!conn->db)
    die("Memory error");

  if(mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if(conn->file)
      database_load(conn);
  } // end if/else

  if (!conn->file)
    die("Failed to open the file");

  return conn;
} // end database_open

void database_close(struct Connection *conn) {
  if(conn) {
    if(conn->file)
      fclose(conn->file);
    if(conn->db) 
      free(conn->db);
    free(conn);
  } // end if(conn)
} // end database_close

void database_write(struct Connection *conn) {
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), NUM_OF_DB, conn->file);
  if(rc != 1)
    die("Failed to write to database");

  rc = fflush(conn->file);
  if(rc == -1)
    die("Cannot flush database");
} // end database_write


void database_create(struct Connection *conn) {
  for(int i = 0; i < MAX_ROWS; i++) {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = FALSE};
    // assign it to a row
    conn->db->rows[i] = addr;
  } // end for
} // end database_create

void database_set(struct Connection *conn, int id,
                  const char *name, const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if(addr->set)
    die("Already set, delete it first");

  addr->set = TRUE;
  // WARNING: bug, read the "How to break it" and fix this
  char *res = strncpy(addr->name, name, MAX_DATA);
  // demonstrate the strncpy bug
  if(!res)
    die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if(!res)
    die("Email copy failed");

} // end database_set // rename to set_addr

void database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id]; // &conn->db == &(*conn).db &conn->db->rows[id] == &(*conn).(*db).rows[id] ???

  if(addr->set)
    address_print(addr);
  else
    die("ID is not set");
} // end database_get // rename to read_address

void database_delete(struct Connection *conn, int id) {
  // create empty address
  struct Address addr = {.id = id, .set = FALSE};
  conn->db->rows[id] = addr; //replace current address with empty address
} // end database_delete // rename to delete_address

void database_list(struct Connection *conn) {
  struct Database *db = conn->db; // ptr to database to connection
  for(int i = 0; i < MAX_ROWS; i++) { // for all possible addresses
    struct Address *cur = &db->rows[i]; // ptr to address
    if(cur->set) // if there is a valid address
      address_print(cur); // print it out
  } // end for
} // end database_list

int main (int argc, char* argv[]) {
  if(argc < 3)
    die("Useage: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1]; // get filename from command line
  char action = argv[2][0]; // get user decided action from command line
  // open a new connection
  struct Connection *conn = database_open(filename, action);
  int id = 0;

  if(argc > 3)
    id = atoi(argv[3]);
  if(id >= MAX_ROWS)
    die("id exceeds number of possible records to access");

  switch(action) {
    case 'c':
      database_create(conn); // create database
      database_write(conn); // write file to database
      break;

    case 'g':
      if(argc != 4)
        die("Need an id to get");
      database_get(conn, id); // get record
      break;

    case 's':
      if(argc != 6)
        die("Need id, name, email to set");
      database_set(conn, id, argv[4], argv[5]);
      database_write(conn);
      break;

    case 'd':
      if(argc != 4)
        die("Need id to delete");

      database_delete(conn, id); // delete record
      database_write(conn); //rewrite database to file
      break;

    case 'l':
      database_list(conn); // list out all records in the database
      break;

    default:
      die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }

  database_close(conn);

  return 0;
}