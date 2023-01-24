<?php

$a = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
$b = array(array(7, 8, 9), array(4, 5, 6), array(1, 2, 3));

$m = count($a);
$n = count($a[0]);

$p = count($b);
$q = count($b[0]);

echo "the first matrix : <br/>";

for ($r = 0; $r < $m; $r++) {
	for ($c = 0; $c < $n; $c++)
		echo " " . $a[$r][$c];
	echo "<br/>";
}

echo "the second matrix :" . "<br/>";

for ($r = 0; $r < $p; $r++) {
	for ($c = 0; $c < $q; $c++)
		echo " " . $b[$r][$c];
	echo "<br/>";
}

echo "the transpose for the first matrix is:" . "<br/>";

for ($c = 0; $c < $n; $c++) {
	for ($r = 0; $r < $m; $r++)
		echo " " . $a[$r][$c];
	echo "<br/>";
}

if (($m === $p) and ($n === $q)) {
	echo "the addition of matrices is:" . "<br/>";

	for ($r = 0; $r < $m; $r++) {
		for ($c = 0; $c < $n; $c++)
			echo " " . ($a[$r][$c] + $b[$r][$c]);
		echo "<br/>";
	}
} else {
	echo "Matrices can't be added <br>";
}

if ($n === $p) {
	echo " The multiplication of matrices: <br/>";

	$result = array();

	for ($i = 0; $i < $m; $i++) {
		for ($j = 0; $j < $q; $j++) {
			$result[$i][$j] = 0;
			for ($k = 0; $k < $n; $k++)
				$result[$i][$j] += $a[$i][$k] * $b[$k][$j];
			echo " " . $result[$i][$j];
		}
		echo "<br>";
	}
} else {
	echo "Matrices can't be multiplied <br>";
}
