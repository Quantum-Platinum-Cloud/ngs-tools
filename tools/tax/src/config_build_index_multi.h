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

#ifndef CONFIG_BUILD_INDEX_H_INCLUDED
#define CONFIG_BUILD_INDEX_H_INCLUDED

#include <string>
#include "log.h"

struct Config
{
	std::string file_list;
	unsigned int kmer_len, window_size, pos_encoding_mul;

	Config(int argc, char const *argv[])
	{
		if (argc != 5)
		{
			print_usage();
			exit(1);
		}

		file_list = std::string(argv[1]);
		kmer_len = std::stoi(std::string(argv[2]));
        window_size = std::stoi(std::string(argv[3]));
        pos_encoding_mul = std::stoi(std::string(argv[4]));
	}

	static void print_usage()
	{
        LOG("need <files.list> <kmer len> <window size> <pos encoding mul>");
	}
};

#endif
