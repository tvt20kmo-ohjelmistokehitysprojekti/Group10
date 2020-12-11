<?php
class Transfer_model extends CI_model
{
function Transfer_money($idAccount1, $idAccount2, $amount) {
        $this->db->query("call debit_transfer($idAccount1,$idAccount2,$amount)");
        if($this->db->affected_rows()>0) {
            return true;
        }
        else {
            return false;
        }
    }
}
