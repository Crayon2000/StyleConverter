# StyleConverter
This command line tool is used to convert RAD Studio FireMonkey style format.
It was mainly designed to minimize the size of a style file included in resource.
The application is coded with C++Builder.

```bash
Usage: StyleConverter.exe file [-f format]
file    style file to convert
  -f    format: 0=Indexed, 1=Binary, 2=Text
```

Style file extensions used in RAD Studio:

Extension | Description
--------- | -------------
.Style    | FireMonkey text style file
.fsf      | FireMonkey binary style file
.vsf      | VCL style file (not supported in this tool)

### Examples

Convert a Style file to fsf
```bash
StyleConverter Air.Style -f0
```
Convert a fsf to Style file
```bash
StyleConverter GoogleGlass.fsf -f2
```