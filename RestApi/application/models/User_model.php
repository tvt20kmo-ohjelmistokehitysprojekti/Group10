
<?php
/**
 *
 */
class User_model extends CI_model
{
  function get_user($id){
    $this->db->select('Balance');
    $this->db->from('Account');
    if($id !== NULL) {
      $this->db->where('idAccount',$id);
    }
    return $this->db->get()->result_array();
  }

}

