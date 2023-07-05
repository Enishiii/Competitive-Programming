<?php

function sumTillN($n) {
    return ($n * ($n+1)) / 2;
}

function sumOfMultiplesTillN($n, $a) {
    return sumTillN(intval($n / $a)) * $a;
}

list($n, $a, $b) = explode(' ', trim(fgets(STDIN)));

$lcm = gmp_strval(gmp_lcm($a, $b));
$ans = sumTillN($n);

$ans -= sumOfMultiplesTillN($n, $a);
$ans -= sumOfMultiplesTillN($n, $b);
$ans += sumOfMultiplesTillN($n, $lcm);

echo $ans . PHP_EOL;
