/*
 * (C) 2024 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <afxdlgs.h>

// CSaveFileDialog

class CSaveFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CSaveFileDialog)

private:
	// CFileDialog::GetPathName does not work for long paths, use GetFilePath instead.
	CFileDialog::GetPathName;

	std::unique_ptr<WCHAR[]> m_pstrInitialDir;

public:
	CSaveFileDialog(
		LPCWSTR lpszDefExt = NULL,
		LPCWSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCWSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);
	virtual ~CSaveFileDialog() = default;

	// Returns the file path selected for saving. Long paths are supported.
	CStringW GetFilePath();
};