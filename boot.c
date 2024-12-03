/* SPDX-License-Identifier: LGPL-2.1+ */
/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * Copyright (C) 2012-2015 Kay Sievers <kay@vrfy.org>
 * Copyright (C) 2012-2015 Harald Hoyer <harald@redhat.com>
 */

#define  GNU_EFI_USE_MS_ABI


#include <efi.h>
#include "efibind1.h"
#include <efilib.h>


void mmm(void)
{
	uefi_call_wrapper(ST->ConOut->OutputString, 2, ST->ConOut, L"\b \b");
}

/*
EFI_STATUS efi_main(EFI_HANDLE image, EFI_SYSTEM_TABLE *sys_table) 
{

	InitializeLib(image, sys_table);  // I need It.
	
	Print(L"\nFailed to execute....\n");
	uefi_call_wrapper(BS->Stall, 1, 3 * 1000 * 1000);
	return EFI_SUCCESS;
}
*/
