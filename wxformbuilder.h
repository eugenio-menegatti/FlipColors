///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 21 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/html/htmlwin.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainDialogBase
///////////////////////////////////////////////////////////////////////////////
class MainDialogBase : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText30;
		wxRadioBox* m_radioBox32;
		wxCheckBox* m_checkBox38;
		wxRadioBox* m_radioBox36;
		wxButton* startButton;
		wxStaticLine* m_staticLine15;
		wxButton* quitButton;
		wxButton* licenseButton;
		wxButton* thirdPartyLibs;

		// Virtual event handlers, overide them in your derived class
		virtual void OnStartGameButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLicenseButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnThirdPartyButtonClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("FlipColors"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~MainDialogBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class GameArea
///////////////////////////////////////////////////////////////////////////////
class GameArea : public wxFrame
{
	private:

	protected:

	public:

		GameArea( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GameArea"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE );

		~GameArea();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PassDialogBase
///////////////////////////////////////////////////////////////////////////////
class PassDialogBase : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText533;
		wxTextCtrl* m_textCtrl554;
		wxStaticText* m_staticText575;
		wxButton* m_button636;

	public:

		PassDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Informazione"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PassDialogBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class LicensesDialogBase
///////////////////////////////////////////////////////////////////////////////
class LicensesDialogBase : public wxDialog
{
	private:

	protected:
		wxHtmlWindow* legalHTMLbox;
		wxButton* m_button8;

	public:

		LicensesDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Third party licenses"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,318 ), long style = wxDEFAULT_DIALOG_STYLE );
		~LicensesDialogBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BSDLicenseDialogBase
///////////////////////////////////////////////////////////////////////////////
class BSDLicenseDialogBase : public wxDialog
{
	private:

	protected:
		wxHtmlWindow* legalHTMLbox;
		wxButton* m_button8;

	public:

		BSDLicenseDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Third party licenses"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,318 ), long style = wxDEFAULT_DIALOG_STYLE );
		~BSDLicenseDialogBase();

};

