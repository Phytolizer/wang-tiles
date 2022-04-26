import std/[
  strformat,
]

const
  WIDTH = 64
  HEIGHT = 64

proc main =
  let f = open("output.ppm", fmWrite)
  defer: f.close()

  f.writeLine("P6")
  f.writeLine(fmt"{WIDTH} {HEIGHT}")
  f.writeLine("255")
  for y in 0..<HEIGHT:
    for x in 0..<WIDTH:
      let r = x / WIDTH
      let g = y / HEIGHT
      let b = 0.5
      f.write(chr(int(r * 255)))
      f.write(chr(int(g * 255)))
      f.write(chr(int(b * 255)))

when isMainModule:
  main()
