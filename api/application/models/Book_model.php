<?php
/**
 *
 */
class Book_model extends CI_model
{
  function get_book($id){
    $this->db->select('*');
    $this->db->from('book');
    if($id !== NULL) {
      $this->db->where('id_book',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_book($add_data){
    $this->db->insert('book',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_book($id, $update_data){
    $this->db->where('id_book',$id);
    $this->db->update('book',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_book($id){
    $this->db->where('id_book',$id);
    $this->db->delete('book');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}
