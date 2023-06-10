<?php

list($numStrings, $lengthStrings) = explode(" ", trim(fgets(STDIN)));

$strings = [];
for ($i = 0; $i < $numStrings; ++$i) {
    $strings[] = trim(fgets(STDIN));
}

sort($strings);

echo implode("", $strings);
