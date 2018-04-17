object Form1: TForm1
  Left = 124
  Top = 331
  Width = 630
  Height = 373
  Caption = 'Form'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object FieldImage: TImage
    Left = 32
    Top = 24
    Width = 473
    Height = 297
  end
  object Button1: TButton
    Left = 520
    Top = 264
    Width = 89
    Height = 25
    Caption = 'Start'
    TabOrder = 0
    OnClick = StartClick
  end
  object Button2: TButton
    Left = 520
    Top = 296
    Width = 89
    Height = 25
    Caption = 'Stop'
    TabOrder = 1
    OnClick = StopClick
  end
end
