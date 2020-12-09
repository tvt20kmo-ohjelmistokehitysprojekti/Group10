<?php
/**
 *
 */
class Action_model extends CI_model
{
  function get_user($id){
    $this->db->select('*');
    $this->db->from('Action');
    if($id !== NULL) {
      $this->db->where('Account',$id);
    }
    return $this->db->get()->result_array();
  }

}
