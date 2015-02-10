
void send_heartbeat_1() {
      
      // Define items for heartbeat
      mavlink_message_t msg_1;
      mavlink_heartbeat_t heartbeat_1;
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
      
      heartbeat_1.base_mode = 0; 
      heartbeat_1.custom_mode = 0;
      heartbeat_1.system_status = MAV_STATE_UNINIT;
      heartbeat_1.type = MAV_TYPE_GCS;  //MAV_TYPE_GCS if you want to comunicate with drone, MAV_TYPE_GENERIC if you want to comunicate with GCS
      heartbeat_1.autopilot = MAV_AUTOPILOT_INVALID;
  
      // Pack the message
      // mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t type, uint8_t autopilot)
      mavlink_msg_heartbeat_pack(multirotor_1.getGcsId(), multirotor_1.getGcsId(), &msg_1, heartbeat_1.type, heartbeat_1.autopilot, heartbeat_1.base_mode, heartbeat_1.custom_mode, heartbeat_1.system_status);
	
      // Copy the message to send buffer 
      uint16_t len = mavlink_msg_to_send_buffer(buf, &msg_1);
	
      // Send the message (.write sends as bytes) 
      Serial1.write(buf, len);
}

void send_heartbeat_2() {
      
      // Define items for heartbeat
      mavlink_message_t msg_2;
      mavlink_heartbeat_t heartbeat_2;
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
      
      heartbeat_2.base_mode = 0; 
      heartbeat_2.custom_mode = 0;
      heartbeat_2.system_status = MAV_STATE_UNINIT;
      heartbeat_2.type = MAV_TYPE_GCS;  //MAV_TYPE_GCS if you want to comunicate with drone, MAV_TYPE_GENERIC if you want to comunicate with GCS
      heartbeat_2.autopilot = MAV_AUTOPILOT_INVALID;
  
      // Pack the message
      // mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t type, uint8_t autopilot)
      mavlink_msg_heartbeat_pack(multirotor_2.getGcsId(), multirotor_2.getGcsId(), &msg_2, heartbeat_2.type, heartbeat_2.autopilot, heartbeat_2.base_mode, heartbeat_2.custom_mode, heartbeat_2.system_status);
	
      // Copy the message to send buffer 
      uint16_t len = mavlink_msg_to_send_buffer(buf, &msg_2);
	
      // Send the message (.write sends as bytes) 
      Serial2.write(buf, len);
}
