/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _hpp_ngs_operation_
#define _hpp_ngs_operation_

#include <stdlib.h>
#include <stdint.h>

namespace ngs
{
    class ReadCollection;
    class ReferenceSequence;
}
namespace fastrq
{
    /*======================================================================
     * forwards
     */
    class FastRQFilter;
    class FastRQFormatter;

    /*======================================================================
     * operation
     */
    struct FastRQOperation
    {
        virtual void run ( ngs :: ReadCollection & run, const FastRQFilter * filter, const FastRQFormatter * fmt ) const;
        virtual void run ( ngs :: ReadCollection & run, uint64_t start_row, uint64_t num_rows,
            const FastRQFilter * filter, const FastRQFormatter * fmt ) const;

        virtual void run ( ngs :: ReferenceSequence & ref, const FastRQFilter * filter, const FastRQFormatter * fmt ) const;
        virtual void run ( ngs :: ReferenceSequence & ref, uint64_t start_row, uint64_t num_rows,
            const FastRQFilter * filter, const FastRQFormatter * fmt ) const;

        FastRQOperation (); 
        virtual ~FastRQOperation (); 
    };

    FastRQOperation * makeReadOperation ();
    FastRQOperation * makeReadOperation ( uint64_t start_row, uint64_t num_rows );

    FastRQOperation * makeRefSeqOperation ();
}

#endif // _hpp_ngs_operation_
