object frmHighScores: TfrmHighScores
  Left = 390
  Top = 198
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsNone
  Caption = 'High Scores'
  ClientHeight = 353
  ClientWidth = 234
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 234
    Height = 41
    Align = alTop
    Caption = 'High Scores'
    Font.Charset = ANSI_CHARSET
    Font.Color = clNavy
    Font.Height = -27
    Font.Name = 'Book Antiqua'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 0
    Top = 312
    Width = 233
    Height = 41
    TabOrder = 1
    Kind = bkOK
  end
  object strgrHighScores: TStringGrid
    Left = 0
    Top = 40
    Width = 233
    Height = 273
    ColCount = 2
    DefaultColWidth = 114
    DefaultRowHeight = 26
    FixedCols = 0
    RowCount = 10
    TabOrder = 2
  end
end
