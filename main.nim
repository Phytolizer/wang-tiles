import std/[
  strformat,
]

const
  WIDTH = 128
  HEIGHT = 128

proc main =
  let f = open("output.ppm", fmWrite)
  defer: f.close()

  f.writeLine("P6")
  f.writeLine(fmt"{WIDTH} {HEIGHT} 255")
  for y in 0..<HEIGHT:
    for x in 0..<WIDTH:
      let u = x / WIDTH
      let v = y / HEIGHT
      f.write(chr(int(u * 255)))
      f.write(chr(int(v * 255)))
      f.write(chr(0))

when isMainModule:
  main()
