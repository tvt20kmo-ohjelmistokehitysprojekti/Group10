<?php
class Withdraw_model extends CI_model
{
function withdraw_money($idAccount, $amount) {
        $this->db->query("call withdraw($idAccount,$amount)");
        if($this->db->affected_rows()>0) {
            return true;
        }
        else {
            return false;
        }
    }
}
