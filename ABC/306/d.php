<?php

const INF = 1e18;

function chmax(&$x, $y) {
    $x = max($x, $y);
}

function calculateMaximumTastiness($x, $y, $n) {
    $dp = array_fill(0, $n+1, array_fill(0, 2, -INF));
    $dp[0][0] = 0;

    for ($i = 0; $i < $n; ++$i) {
        chmax($dp[$i+1][0], $dp[$i][0]);
        chmax($dp[$i+1][1], $dp[$i][1]);

        if ($x[$i] === 0) {
            chmax($dp[$i+1][0], $dp[$i][0]+$y[$i]);
            chmax($dp[$i+1][0], $dp[$i][1]+$y[$i]);
        } else {
            chmax($dp[$i+1][1], $dp[$i][0]+$y[$i]);
        }
    }

    return max($dp[$n][0], $dp[$n][1]);
}

$n = intval(trim(fgets(STDIN)));
$x = array();
$y = array();
for ($i = 0; $i < $n; ++$i) {
    fscanf(STDIN, "%d%d", $x[], $y[]);
}

$ans = calculateMaximumTastiness($x, $y, $n);
echo $ans . PHP_EOL;
