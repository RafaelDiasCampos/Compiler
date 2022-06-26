
$Tests = Get-ChildItem -Directory -Path '..\tests\'

$Filenames = @("original", "fixedString", "fixedLexic")
$TestType = "lexico"

$Compiler = "../build/Compiler.exe"

foreach ($Test in $Tests) {
    $FolderName = $Test.name
    $OutputFolder = "./3-testes/$TestType/$FolderName"
    
    if (!(Test-Path -Path $OutputFolder)) {
        $null = New-Item -ItemType Directory -Force -Path $OutputFolder
    }

    foreach ($Filename in $Filenames) {
        $InputFile = "$Test/$Filename.txt"
        $OutputFile = "$OutputFolder/$Filename.txt"
        $exists = (Test-Path -Path $InputFile -PathType Leaf)
        if ($exists) {
            Invoke-Expression "$Compiler $InputFile > $OutputFile"
        }
    }
}