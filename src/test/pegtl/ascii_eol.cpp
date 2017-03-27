// Copyright (c) 2016-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include "test.hpp"

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      void unit_test()
      {
         verify_analyze< eol >( __LINE__, __FILE__, true, false );

         verify_rule< eol >( __LINE__, __FILE__, "", result_type::LOCAL_FAILURE, 0 );

         for( char i = 1; i < 127; ++i ) {
            verify_char< eol >( __LINE__, __FILE__, i, ( i == '\n' ) ? result_type::SUCCESS : result_type::LOCAL_FAILURE );
         }
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\r", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\n", result_type::SUCCESS, 0 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\r\n", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\n\r", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\n\r\n", result_type::SUCCESS, 2 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\n\r\r", result_type::SUCCESS, 2 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\na", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\ra", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\r\na", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\r\n\r", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, lf_eol >( __LINE__, __FILE__, "\r\n\n", result_type::LOCAL_FAILURE, 3 );

         verify_impl< eol, cr_eol >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\r", result_type::SUCCESS, 0 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\n", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\r\n", result_type::SUCCESS, 1 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\n\r", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\n\r\n", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\n\r\r", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\na", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\ra", result_type::SUCCESS, 1 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\r\na", result_type::SUCCESS, 2 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\r\n\r", result_type::SUCCESS, 2 );
         verify_impl< eol, cr_eol >( __LINE__, __FILE__, "\r\n\n", result_type::SUCCESS, 2 );

         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\r", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\n", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\r\n", result_type::SUCCESS, 0 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\n\r", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\n\r\n", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\n\r\r", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\na", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\ra", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\r\na", result_type::SUCCESS, 1 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\r\n\r", result_type::SUCCESS, 1 );
         verify_impl< eol, crlf_eol >( __LINE__, __FILE__, "\r\n\n", result_type::SUCCESS, 1 );

         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\r", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\n", result_type::SUCCESS, 0 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\r\n", result_type::SUCCESS, 0 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\n\r", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\n\r\n", result_type::SUCCESS, 2 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\n\r\r", result_type::SUCCESS, 2 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\na", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\ra", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\r\na", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\r\n\r", result_type::SUCCESS, 1 );
         verify_impl< eol, lf_crlf_eol >( __LINE__, __FILE__, "\r\n\n", result_type::SUCCESS, 1 );

         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\r", result_type::SUCCESS, 0 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\n", result_type::LOCAL_FAILURE, 1 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\r\n", result_type::SUCCESS, 0 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\n\r", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\n\r\n", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\n\r\r", result_type::LOCAL_FAILURE, 3 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\na", result_type::LOCAL_FAILURE, 2 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\ra", result_type::SUCCESS, 1 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\r\na", result_type::SUCCESS, 1 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\r\n\r", result_type::SUCCESS, 1 );
         verify_impl< eol, cr_crlf_eol >( __LINE__, __FILE__, "\r\n\n", result_type::SUCCESS, 1 );
      }

   }  // namespace TAOCPP_PEGTL_NAMESPACE

}  // namespace tao

#include "main.hpp"
