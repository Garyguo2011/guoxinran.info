<?php
	$pageTitle = "Porjects";
	$section = "projects";
	include('inc/header.php'); 
?>
	<div id="banner">&nbsp;</div>
	<div id="content">
		<div class="post">
			<h2 class="title"><a href="mapreduce.php">MapReduce</a></h2>
			<p class="meta">Posted on Feb 4th 2014</p>
			<div class="entry">
				<ul>
					<li>Apache Hadoop as platform, used Java, implemented MapReduce algorithms that listed high co-occurrence rate word related to a target word in documents</li>
					<li>Fast learned Java, got familiar with Java and Hadoop API, and improved the algorithm efficiency to calculate the relative distance between each word with target word.</li>
					<li>Utilized Amazon EC2 servers, ran program in test larger database, analyzed the performance via different algorithms.</li>
				</ul>
			</div>
		</div>

		<div class="post">
			<h2 class="title"><a href="#">Images Processing and Optimization</a></h2>
			<p class="meta">Posted on Feb 4th 2014</p>
			<div class="entry">
				<ul>
					<li>Used C language, optimized a formula for doing 2D (Matrixes) convolution on images by using knowledge of parallelism.</li>
					<li>Solved major issues that various technologies of parallelism caused mistakes when it applied to the edges of images. Improved the compatibility of algorithm so that the formula can apply to any size of images efficiently</li>
					<li>Optimized the formula 85 times faster (Only required 35 times) by using Intel SSE instructions, Register Blocking, Loop Unrolling, Cache Blocking, and OpenMP.</li>
				</ul>

			</div>
		</div>

		<div class="post">
			<h2 class="title"><a href="#">Student Information Model</a></h2>
			<p class="meta">Posted on Feb 4th 2014</p>
			<div class="entry">
				<p>Led team of four to build a proof-of-concept information system to manage student academic records, including efficient information storage and retrieval. Designed the architecture, integrated others' modules, and built a test suite to verify data integrity.</p>
			</div>
		</div>

		<div class="post">
			<h2 class="title"><a href="#">Processor (CPU) Design</a></h2>
			<p class="meta">Posted on Feb 4th 2014</p>
			<div class="entry">
				<ul>
					<li>Logisim as platform, used logic circuit to built two-cycle MIPS processor units, data path, and Pipelining.</li>
					<li>Clearly built Register File, ALU, CPU, Data Memory and Output Devices, implemented pipeline to optimize the performance and solved pipelining Hazards.</li>
					<li>Efficiently and successfully ran multiple machine codes in processor with all phases (Instruction Fetch, Decode/Register Read, Execute, Register Write).</li>
				</ul>
			</div>
		</div>

		<div class="post">
			<h2 class="title"><a href="#">Scheme Interpreter</a></h2>
			<p class="meta">Posted on Feb 4th 2014</p>
			<div class="entry">
				<p>Implemented Scheme interpreter in Python, supporting control, recursion, higher-order functions, and user-defined procedures. Optimized performance by streamlining calls to subroutines and taking advantage of recursive data structures.</p>
			</div>
		</div>




	</div>
<?php include('inc/sidebar.php'); ?>
<?php include('inc/footer.php'); ?>