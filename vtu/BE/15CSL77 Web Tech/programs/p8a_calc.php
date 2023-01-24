<html>

<body>
	<?php
	// checks if the input sub is set in post request
	if (isset($_POST['sub'])) {
		$num1 = $_POST['n1'];
		$num2 = $_POST['n2'];
		$op = $_POST['sub'];

		// if (is_numeric($num1) and is_numeric($num2))
		if ($op == "+")
			$res = $num1 + $num2;
		else if ($op == "-")
			$res = $num1 - $num2;
		else if ($op == "x")
			$res = $num1 * $num2;
		else if ($op == "/")
			$res = $num1 / $num2;
	}
	?>

	<!-- POST req is sent to the same route (this file) & gets processed in the above php block -->
	<form method="post">
		Calculator
		<br>
		No1:<input type="number" name="n1" value="<?php echo $num1; ?>">
		<br>
		No2:<input type="number" name="n2" value="<?php echo $num2; ?>">
		<br>
		Res:<input type="text" name="res" value="<?php echo $res; ?>" readonly>
		<br>
		<input type="submit" name="sub" value="+">
		<input type="submit" name="sub" value="-">
		<input type="submit" name="sub" value="x">
		<input type="submit" name="sub" value="/">
	</form>

</body>

</html>
