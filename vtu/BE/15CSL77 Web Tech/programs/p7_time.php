<!-- Method 1. Refresh whole page -->

<head>
	<!-- <meta http-equiv="refresh" content="1" /> -->
	<style>
		body {
			background-color: black;
			color: white;
			font-size: 90px;
		}

		p {
			margin: 0;
			position: absolute;
			top: 50%;
			left: 50%;
			transform: translate(-50%, -50%);
		}
	</style>
</head>

<body>
	<p>
		<?php
		// date_default_timezone_set('Asia/Calcutta');
		echo date("h:i:s A");
		?>
	</p>
</body>

<!-- Method 2. Make ajax calls to route (php file) which returns time -->

<!-- Method 3. Get time once and handle rest in JS -->
<!-- <script>
	// PHP returns time in seconds
	var d = new Date(<?php echo time() * 1000 ?>);

	function digitalClock() {
		// As this is called every second
		d.setTime(d.getTime() + 1000);

		var hrs = d.getHours();
		var mins = d.getMinutes();
		var secs = d.getSeconds();

		var apm = (hrs < 12) ? "am" : "pm";

		mins = (mins < 10 ? "0" : "") + mins;
		secs = (secs < 10 ? "0" : "") + secs;
		hrs = (hrs > 12) ? hrs - 12 : hrs;
		hrs = (hrs == 0) ? 12 : hrs;

		document.getElementById("clock").innerHTML = hrs + ":" + mins + ":" + secs + " " + apm;
	}
	window.onload = function() {
		setInterval('digitalClock()', 1000);
	}
</script>
<p id="clock"> </p> -->
