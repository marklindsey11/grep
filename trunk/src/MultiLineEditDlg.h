// grepWin - regex search and replace for Windows

// Copyright (C) 2011-2013 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include "BaseDialog.h"
#include "DlgResizer.h"
#include "AeroControls.h"
#include <string>
#include <vector>


#define ID_REGEXTIMER       100

/**
 * regex test dialog.
 */
class CMultiLineEditDlg : public CDialog
{
public:
    CMultiLineEditDlg(HWND hParent);
    ~CMultiLineEditDlg(void);

    void                    SetString(const std::wstring& search) { m_RegexText = search; }
    std::wstring            GetSearchString() {return m_RegexText;}

protected:
    LRESULT CALLBACK        DlgFunc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT                 DoCommand(int id, int msg);
    void                    DoRegex();

private:
    HWND                    m_hParent;
    std::wstring            m_RegexText;

    CDlgResizer             m_resizer;
    AeroControlBase         m_aerocontrols;
};
