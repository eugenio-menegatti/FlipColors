///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 21 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxformbuilder.h"

 ///////////////////////////////////////////////////////////////////////////

MainDialogBase::MainDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("FlipColors - a simple program that plays a famous game."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer2->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Copyright 2019, Eugenio Menegatti. All rights reserved."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer2->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("WHITE moves first."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer2->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxString m_radioBox32Choices[] = { wxT("Black"), wxT("White") };
	int m_radioBox32NChoices = sizeof( m_radioBox32Choices ) / sizeof( wxString );
	m_radioBox32 = new wxRadioBox( this, wxID_ANY, wxT("Player is"), wxDefaultPosition, wxDefaultSize, m_radioBox32NChoices, m_radioBox32Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox32->SetSelection( 1 );
	bSizer3->Add( m_radioBox32, 0, wxALL, 5 );

	m_checkBox38 = new wxCheckBox( this, wxID_ANY, wxT("Automatic pass"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox38->SetValue(true);
	bSizer3->Add( m_checkBox38, 0, wxALL, 5 );

	wxString m_radioBox36Choices[] = { wxT("Random"), wxT("Longest Path"), wxT("Best Choice (Minimax)"), wxT("Artificial Intelligence (Linear Regression)") };
	int m_radioBox36NChoices = sizeof( m_radioBox36Choices ) / sizeof( wxString );
	m_radioBox36 = new wxRadioBox( this, wxID_ANY, wxT("Computer's move"), wxDefaultPosition, wxDefaultSize, m_radioBox36NChoices, m_radioBox36Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox36->SetSelection( 3 );
	bSizer3->Add( m_radioBox36, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	startButton = new wxButton( this, wxID_ANY, wxT("Start Game"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( startButton, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticLine15 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticLine15, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	quitButton = new wxButton( this, wxID_CANCEL, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0 );

	quitButton->SetDefault();
	bSizer5->Add( quitButton, 0, wxALL, 5 );

	licenseButton = new wxButton( this, wxID_ANY, wxT("License"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( licenseButton, 0, wxALL, 5 );

	thirdPartyLibs = new wxButton( this, wxID_ANY, wxT("Third Party Licenses"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( thirdPartyLibs, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	startButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnStartGameButtonClicked ), NULL, this );
	licenseButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnLicenseButtonClicked ), NULL, this );
	thirdPartyLibs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnThirdPartyButtonClicked ), NULL, this );
}

MainDialogBase::~MainDialogBase()
{
	// Disconnect Events
	startButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnStartGameButtonClicked ), NULL, this );
	licenseButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnLicenseButtonClicked ), NULL, this );
	thirdPartyLibs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainDialogBase::OnThirdPartyButtonClicked ), NULL, this );

}

GameArea::GameArea( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );


	this->Centre( wxBOTH );
}

GameArea::~GameArea()
{
}

PassDialogBase::PassDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText533 = new wxStaticText( this, wxID_ANY, wxT("Il"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText533->Wrap( 0 );
	bSizer7->Add( m_staticText533, 0, wxALL, 5 );

	m_textCtrl554 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl554->Enable( false );

	bSizer7->Add( m_textCtrl554, 0, wxALL, 5 );

	m_staticText575 = new wxStaticText( this, wxID_ANY, wxT("passa."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText575->Wrap( 0 );
	bSizer7->Add( m_staticText575, 0, wxALL, 5 );


	bSizer6->Add( bSizer7, 1, wxALL|wxEXPAND, 5 );

	m_button636 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button636, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );
}

PassDialogBase::~PassDialogBase()
{
}

LicensesDialogBase::LicensesDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	legalHTMLbox = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer81->Add( legalHTMLbox, 1, wxALL|wxEXPAND, 5 );


	bSizer8->Add( bSizer81, 1, wxEXPAND, 5 );

	m_button8 = new wxButton( this, wxID_CANCEL, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button8, 0, wxALL|wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );
}

LicensesDialogBase::~LicensesDialogBase()
{
}

BSDLicenseDialogBase::BSDLicenseDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	legalHTMLbox = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer81->Add( legalHTMLbox, 1, wxALL|wxEXPAND, 5 );


	bSizer8->Add( bSizer81, 1, wxEXPAND, 5 );

	m_button8 = new wxButton( this, wxID_CANCEL, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button8, 0, wxALL|wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );
}

BSDLicenseDialogBase::~BSDLicenseDialogBase()
{
}
