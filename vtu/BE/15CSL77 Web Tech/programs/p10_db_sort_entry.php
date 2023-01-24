<!-- Is this file necessary w.r.t question? -->
<html>

<body>
	<?php
	// CREATE DATABASE weblab;
	// CREATE TABLE students (usn INT(11) PRIMARY KEY, name VARCHAR(20), email VARCHAR(20), mob INT(11));
	// INSERT INTO students VALUES();

	// server, user, password, database - You can use root with no password?
	$connection = mysqli_connect("localhost", "local", "password", "weblab");

	// if (mysqli_connect_errno()) {
	// 	echo "Failed to connect to MySQL: " . mysqli_connect_error();
	// }

	if (isset($_POST['submit'])) {
		$usn = $_POST['usn'];
		$name = $_POST['name'];
		$email = $_POST['email'];
		$mob = $_POST['mob'];

		$query = "insert into students values(" . $usn . ",'$name','$email','$mob')";
		$result = mysqli_query($connection, $query);

		if ($result) {
			echo "<script>alert('Inserted Successfully');window.location.href='p10_db_sort.php';</script>";
		} else {
			echo "<script>alert('Error in insertion');</script>";
		}
	}
	?>

	<form method="post">
		<h1>Student Entry Form</h1>
		<table>
			<tr>
				<td>USN</td>
				<td><input type="text" name="usn"></td>
			</tr>
			<tr>
				<td>Name</td>
				<td><input type="text" name="name"></td>
			</tr>
			<tr>
				<td>Email</td>
				<td><input type="email" name="email"></td>
			</tr>
			<tr>
				<td>Mobile Number</td>
				<td><input type="number" name="mob"></td>
			</tr>
			<tr>
				<td><input type="submit" name="submit" value="Register"></td>
				<td><input type="reset" name="reset" value="Clear"></td>
			</tr>
		</table>
	</form>
</body>

</html>
