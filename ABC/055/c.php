<?php

$pieces = explode(' ', readline());
$numS = (int)$pieces[0];
$numC = (int)$pieces[1];

$ans = min($numS, floor($numC / 2));
$numC -= $ans * 2;

$ans += floor($numC / 4);

echo $ans;
