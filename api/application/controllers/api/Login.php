<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {
    public function check_login(){
        $this->load->model('User_model');
        $username=$this->input->get('username');
        $plaintext_password=$this->input->get('password');
        $encrypted_password=$this->User_model->check_login($username);

        if(password_verify($plaintext_password,$encrypted_password)){
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}
