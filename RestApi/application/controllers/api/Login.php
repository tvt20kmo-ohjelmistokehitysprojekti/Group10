<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {

    public function check_login(){
        $this->load->model('Login_model');
        $idCard=$this->input->get('idCard');
	$Password=$this->input->get('Password');
        $CorrectPassword=$this->Login_model->check_login($idCard);
        if($CorrectPassword == $Password)
{
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}


