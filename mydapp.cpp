/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include "mydapp.hpp"
#include "mydapp.gen.hpp"
#include <eoslib/db.hpp>

extern "C" {
   void init()  {

   }

   void apply( uint64_t code, uint64_t action ) {
      if( code == N(helloworld) ) {
         if( action == N(change) ) {
        	   auto kv1 = eosio::current_message<key_value>();
            bytes b = eosio::raw::pack(kv1.value);
            uint32_t err = store_str( N(helloworld), N(keyvalue), (char *)kv1.key.get_data(), kv1.key.get_size(), (char*)b.data, b.len);

         } else {
            assert(0, "unknown message");
         }
      }
   }
}
