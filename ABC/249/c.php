<?php

fscanf(STDIN, "%d %d", $n, $k);

$strings = array();
for ($i = 0; $i < $n; ++$i) {
    $strings[] = trim(fgets(STDIN));
}

$maxOccurrence = 0;
for ($bit = 0; $bit < (1 << $n); ++$bit) {
    $charCount = array_fill(0, 26, 0);
    for ($idx = 0; $idx < $n; ++$idx) {
        if (($bit >> $idx) & 1) {
            for ($j = 0; $j < strlen($strings[$idx]); ++$j) {
                $charCount[ord($strings[$idx][$j]) - ord('a')]++;
            }
        }
    }
    $currentOccurrence = array_count_values($charCount)[$k] ?? 0;
    $maxOccurrence = max($maxOccurrence, $currentOccurrence);
}

echo $maxOccurrence . PHP_EOL;
