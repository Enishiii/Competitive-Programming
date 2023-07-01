n, k = gets.split.map(&:to_i)
strings = Array.new(n) { gets.chomp }

max_occurrence = 0
(1 << n).times do |bit|
    char_count = Array.new(26, 0)
    n.times do |idx|
        if ((bit >> idx) & 1) == 1
            strings[idx].each_char { |c| char_count[c.ord - 'a'.ord] += 1 }
        end
    end
    current_occurrence = char_count.count(k);
    max_occurrence = [max_occurrence, current_occurrence].max
end

puts max_occurrence
