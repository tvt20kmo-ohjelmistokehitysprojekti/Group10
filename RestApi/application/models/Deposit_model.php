<?php
class Deposit_model extends CI_model
{
function deposit_money($idAccount, $amount) {
        $this->db->query("call deposit($idAccount,$amount)");
        if($this->db->affected_rows()>0) {
            return true;
        }
        else {
            return false;
        }
    }
}
