<?php

defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

class balance extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('User_model');
    }

    public function index_get()
    {
        // user from a data store e.g. database

        $id = $this->input->get('id');

        // If the id parameter doesn't exist return all users
        if ($id === NULL)
        {
            $Balance=$this->User_model->get_user(NULL);
            // Check if the user data store contains user (in case the database result returns NULL)
            if ($Balance)
            {
                // Set the response and exit
                $this->response($Balance, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No user were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular user.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the user from the database, using the id as key for retrieval.
            $Balance=$this->User_model->get_user($id);
            if (!empty($Balance))
            {
		$a12 = json_encode($Balance);
		$abcd = (string) $a12;
		$new123 = preg_replace( '/[^0-9]/', '', $abcd );
		$new456 = preg_replace("/\s+/", " ", $new123);
                $this->set_response($new456, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'user could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }
}
