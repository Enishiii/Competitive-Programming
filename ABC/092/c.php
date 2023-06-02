<?php

function calculateDifferences($n, $a) {
    $totalDiff = 0;
    $previousVal = 0;

    for ($i = 0; $i < $n; $i++) {
        $totalDiff += abs($previousVal - $a[$i]);
        $previousVal = $a[$i];
    }
    $totalDiff += abs($previousVal);

    for ($i = 0; $i < $n; $i++) {
        $prev = ($i > 0) ? $a[$i - 1] : 0;
        $current = $a[$i];
        $next = ($i < $n - 1) ? $a[$i + 1] : 0;

        $ans = $totalDiff;
        $ans -= abs($prev - $current);
        $ans -= abs($current - $next);
        $ans += abs($prev - $next);

        echo $ans . PHP_EOL;
    }
}

$n = (int)fgets(STDIN);
$a = array_map('intval', explode(' ', trim(fgets(STDIN))));
calculateDifferences($n, $a);
