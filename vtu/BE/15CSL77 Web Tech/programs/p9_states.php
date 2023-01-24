<?php

$states = "Mississippi Alabama Texas Massachusetts Kansas";
$statesList = [];

echo "states : $states";

// that ends in xas
preg_match('/\w*xas\b/', $states, $matches);
$statesList[0] = $matches[0];

// that begins with k and ends in s. Ignore case
preg_match('/\bk\w*s\b/i', $states, $matches);
$statesList[1] = $matches[0];

// that begins with M and ends in s
preg_match('/\bM\w*s\b/', $states, $matches);
$statesList[2] = $matches[0];

// that ends in a
preg_match('/\w*a\b/', $states, $matches);
$statesList[3] = $matches[0];

echo "<br><br>statesList :<br>";
foreach ($statesList as $i => $state)
	print("statesList[$i] = $state<br>");

// RegEx Matching
// \w*		-> Multiple word characters (_, number, letter)
// \b		-> Boundary character (boundary to a \w character)
// 			-> Use it to match beginning and end of a word, rather than a space
// \S		-> Non-space character
// ^		-> Start of the line
// $		-> End of the line
// 'i' flag	-> Ignore case

// multiple matches
// preg_match_all('/\w*xas\b/', $states, $matches);
// $statesList[0] = $matches[0][0];
// $statesList[0] = $matches[0][1];

// Split into array and search
// $statesArray = explode(' ', $states);

// that begins with k and ends in s. Ignore case using 'i' flag
// foreach ($statesArray as $state) {
// 	if (preg_match('/^k.*s$/i', $state))
// 		$statesList[1] = ($state);
// }
