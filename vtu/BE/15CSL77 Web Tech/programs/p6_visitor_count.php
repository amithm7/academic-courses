<?php
echo "<h3> REFRESH PAGE </h3>";

$handle = "p6_counter.txt";
// Check if a text file exists. If not create one and initialize it to zero.
if (!file_exists($handle)) {
	$f = fopen($handle, "w");
	fwrite($f, "0");
	fclose($f);
}

// Read the current value of counter file
$f = fopen($handle, "r");
$counterVal = fread($f, filesize($handle));
fclose($f);

// Start the session: Used whenever the session variable is used.
session_start();

// If the session variable with session name 'visited' is not set
if (!isset($_SESSION['visited'])) {
	// Sets a session cookie in browser
	$_SESSION['visited'] = "yes";
	$counterVal++;
	$f = fopen($handle, "w");
	fwrite($f, $counterVal);
	fclose($f);
}

// Format number to english notation (commas)
$counterVal = number_format($counterVal);

echo "You are visitor number $counterVal to this site";

// READ-MORE: https://www.geeksforgeeks.org/php-program-count-page-views/
