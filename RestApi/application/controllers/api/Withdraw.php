<?php
/**
 * Ready for testing.
 */
defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 *
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Withdraw extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Withdraw_model');
    }

public function index_post() {

         // Update the account balance
         $idAccount=$this->post('idAccount');
         $amount=$this->post('amount');

         $withdraw = $this->Withdraw_model->withdraw_money($idAccount,$amount);

         if ($withdraw){
            $message='Nosto onnistui';
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Nosto epäonnistui'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }
}
