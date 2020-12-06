# LibraryRestApi

This API is based on the project
https://github.com/chriskacerguis/codeigniter-restserver

I have edited the API so that the data is stored on MySQL-database.
You can create the database with the codes in file sql.txt

## Important files

### application/config/database.php
Edit this file, so that the servername, database, username and password is correct

### application/config/config.php
Edit the base url

### application/config/rest.php
Edit so that you use basic_authorization
$config['rest_auth'] = 'basic';
And the username and password
$config['rest_valid_logins'] = ['admin' => '1234'];

### application/config/routes.php
Add this kind of lines:
$route['api/book/book/(:num)'] = 'api/book/book/id/$1';

-Pekka Alaluukas 2020
