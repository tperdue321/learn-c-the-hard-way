# you can write to stdout for debugging purposes, e.g.
# puts "this is a debug message"

def solution(n)
  bin_string = n.to_s(2)
  max_bin_gap = 0
  cur_gap_len = 0
  puts bin_string
  # for each digit in the binary string
  bin_string.each_char do |bin_digit|
    # if beginning or end of a gap
    if bin_digit == '1'
      max_bin_gap = set_new_max(cur_gap_len, max_bin_gap) 
      cur_gap_len = 0
      # flip gap bool val
      gap = !gap
    else
      cur_gap_len += 1
    end
  end
  max_bin_gap
end

def set_new_max(cur_len, max_len)
  # check if current gap is longest
  if cur_len > max_len
    cur_len
  else
    max_len
  end
end

puts solution(1041 )
puts solution(-4 )
puts solution(0 )
puts solution(1 )
puts solution(15 )
puts solution(1111000208 )
