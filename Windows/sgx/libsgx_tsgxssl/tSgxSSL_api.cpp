/*
 * Copyright (C) 2011-2017 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "tcommon.h"
#include "tSgxSSL_api.h"
#include "tsgxssl_version.h"

PRINT_TO_STDOUT_STDERR_CB s_print_cb = NULL;

extern "C" void SGXSSLSetPrintToStdoutStderrCB(PRINT_TO_STDOUT_STDERR_CB cb)
{
	FSTART;

	s_print_cb = cb;

	FEND;
}

//by default OpenSSL does NOT allow proxy certificates
ProxyCertsPolicy_t s_proxy_certs_policy = PROXY_CERTS_NOT_ALLOWED;	

extern "C" void SGXSSLSetProxyCertsPolicy(ProxyCertsPolicy_t isAllowed)
{
	FSTART;

	s_proxy_certs_policy = isAllowed;

	FEND;
}

//by default reaching unreachable code will cause an enclave to be aborted.
UnreachableCodePolicy_t s_unreach_code_policy = UNREACH_CODE_ABORT_ENCLAVE;	

extern "C" void SGXSSLSetUnreachableCodePolicy(UnreachableCodePolicy_t policy)
{
	FSTART;

	s_unreach_code_policy = policy;

	FEND;
}

extern "C" const char * SGXSSLGetSgxSSLVersion()
{
	return SGX_SSL_VERSION_STR;
}