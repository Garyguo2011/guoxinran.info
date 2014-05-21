<?php
	$pageTitle = "contact";
	$section = "contact";
	include('inc/header.php'); 
?>
	<div id="banner">&nbsp;</div>
	<div id="content">
		<div class="post">
				<h1 class="title"><a href="#">Contact</a></h1>
				<p class="meta">I'd like to hear from you</p>
				<div class="entry">
					<form method="post" action="contact.php">

            <table>
                <tr>
                    <th>
                        <label for="name">Name</label>
                    </th>
                    <td>
                        <input type="text" name="name" id="name">
                    </td>
                </tr>
                <tr>
                    <th>
                        <label for="email">Email</label>
                    </th>
                    <td>
                        <input type="text" name="email" id="email">
                    </td>
                </tr>
                <tr>
                    <th>
                        <label for="message">Message</label>
                    </th>
                    <td>
                        <textarea name="message" id="message"></textarea>
                    </td>
                </tr>                    
            </table>
            <input type="submit" value="Send">

          </form>
				</div>
		</div>
	</div>
<?php include('inc/sidebar.php'); ?>
<?php include('inc/footer.php'); ?>