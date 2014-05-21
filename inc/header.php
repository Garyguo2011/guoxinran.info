<html>
<head>
<meta name="keywords" content="" />
<meta name="description" content="" />
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title><?php echo "$pageTitle"; ?></title>
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
</head>

<body>
<div id="wrapper">
	<div id="header">
		<div id="logo">
			<h1><a href="#"> Gary(Xinran) Guo </a></h1>
			<p>Junior EECS Student at UC Berkeley</p>
		</div>
	</div>
	<!-- end #header -->
	<div id="menu">
		<ul>
			<li class="<?php if($section == "home"){echo "on";} ?>"><a href="index.php">Home</a></li>
			<li class="<?php if($section == "resume"){echo "on";} ?>"><a href="resume.php">Resume</a></li>
			<li class="<?php if($section == "projects"){echo "on";} ?>"><a href="projects.php">Projects</a></li>
			<li class="<?php if($section == "experience"){echo "on";} ?>"><a href="experiences.php">Experiences</a></li>
			<li class="<?php if($section == "interests"){echo "on";} ?>"><a href="interests.php">Interests</a></li>
			<li class="<?php if($section == "contact"){echo "on";} ?>"><a href="contact.php">Contact</a></li>
		</ul>
	</div>
	<!-- end #menu -->
	<div id="page">