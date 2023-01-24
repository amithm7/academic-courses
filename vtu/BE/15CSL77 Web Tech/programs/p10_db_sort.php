<?php
$connect = mysqli_connect("localhost", "local", "password", "weblab");

$result = mysqli_query($connect, "select * from students");

if (mysqli_num_rows($result) > 0) {
	$ids = [];
	$i = 0;

	echo "<h3>Before Sorting</h3>";
	while ($row = mysqli_fetch_assoc($result)) {
		$ids[$i] = $row['usn'];
		echo $ids[$i] . "<br/>";
		$i++;
	}

	$ids = selectionSort($ids);
	
	echo "<h3>After Sorting</h3>";
	for ($i = 0; $i < count($ids); $i++) {
		echo $ids[$i] . "<br/>";
	}
	
	echo "<h3>Sorted Data</h3>";
	echo "<table border='2'><tr><th>USN</th><th>NAME</th><th>EMAIL</th><th>MOBILE</th></tr>";
	for ($i = 0; $i < count($ids); $i++) {
		$result = mysqli_query($connect, "select * from students where usn='$ids[$i]'");
	
		if (mysqli_num_rows($result) > 0) {
			if ($row = mysqli_fetch_assoc($result)) {
				echo "<tr>";
				echo "<td>" . $row['usn'] . "</td>";
				echo "<td>" . $row['name'] . "</td>";
				echo "<td>" . $row['email'] . "</td>";
				echo "<td>" . $row['mob'] . "</td>";
				echo "</tr>";
			}
		}
	}
	echo "</table>";
} else {
	echo "no data";
}

// Selection sort
function selectionSort($list)
{
	$len = count($list);
	for ($i = 0; $i < $len - 1; $i++) {
		// Assume first index as minimum
		$min = $i;

		// Test against elements after i
		for ($j = $i + 1; $j < $len; $j++) {
			if ($list[$j] < $list[$min]) {
				// Found new minimum
				$min = $j;
			}
		}

		// If min index is not i (assumed), swap their elements
		if ($min != $i) {
			$temp = $list[$i];
			$list[$i] = $list[$min];
			$list[$min] = $temp;
		}
	}
	return $list;
}
