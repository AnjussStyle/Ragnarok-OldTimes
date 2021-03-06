// ArqCfg criado por Junior, agradecimentos por esta linda ajuda
unit ArqCfg;

interface

  uses SysUtils, Dialogs;

  type ArquivoCfg = class
    private
      linhas : array[0..1000] of string;
      arquivo : string;
      qtlinhas : integer;

    public
      constructor Criar(arquivo, mensagem : string);
      function Obter(chave : string) : string;
      procedure Definir(chave, valor : string);
      procedure Salvar();      
  end;

implementation
  constructor ArquivoCfg.Criar(arquivo, mensagem : string);
  var h : TextFile;
  var linha : string;
  var i : integer;
  begin
    self.arquivo := arquivo;
    i := 0;
    AssignFile(h, arquivo);
    try
      Reset(h);
    except
      ShowMessage(mensagem);
    end;
                
    while not Eof(h) do
    begin
      ReadLn(h, linha);
      linhas[i] := linha;
      i := i +1;
    end;
    qtlinhas := i;
    CloseFile(h);
  end;

  function ArquivoCfg.Obter(chave : string) : string;
  var i : integer;
  var k, v, linha : string;
  var posicao : integer;

  begin
    for i:=low(linhas) to high(linhas) do
    begin
      linha := linhas[i];
      if (pos('//', linha)=0) then
      begin
        posicao := pos(':', linha);
        if (posicao>0) then
        begin
          k := trim(copy(linha, 0, posicao-1));
          v := trim(copy(linha, posicao+1, length(linha)-posicao));
          if (k=chave) then
          begin
            Obter := v;
            break;
          end;
        end;
      end;
    end;
  end;

  procedure ArquivoCfg.Definir(chave, valor : string);
  var i : integer;
  var k, v, linha : string;
  var posicao : integer;

  begin
    for i:=low(linhas) to high(linhas) do
    begin
      linha := linhas[i];
      if (pos('//', linha)=0) then
      begin
        posicao := pos(':', linha);
        if (posicao>0) then
        begin
          k := trim(copy(linha, 0, posicao-1));
          v := trim(copy(linha, posicao+1, length(linha)-posicao));
          if (k=chave) then
          begin
            linhas[i] := chave + ': ' + valor;
            break;
          end;
        end;
      end;
    end;
  end;

  procedure ArquivoCfg.Salvar();
  var h : TextFile;
  var linha : string;
  var i : integer;
  begin
    i := 0;
    AssignFile(h, arquivo);
    ReWrite(h);
    for i:=low(linhas) to qtlinhas do
    begin
      WriteLn(h, linhas[i]);
    end;
    CloseFile(h);
  end;
end.
