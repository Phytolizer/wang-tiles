import std/[
  strformat,
]

const
  WIDTH = 128
  HEIGHT = 128

proc frag(u, v: float): tuple[r: float, g: float, b: float] =
  return (u, v, 0.0)

proc main =
  let f = open("output.ppm", fmWrite)
  defer: f.close()

  f.writeLine("P6")
  f.writeLine(fmt"{WIDTH} {HEIGHT} 255")
  for y in 0..<HEIGHT:
    for x in 0..<WIDTH:
      let u = x / WIDTH
      let v = y / HEIGHT
      let (r, g, b) = frag(u, v)
      f.write(chr(int(r * 255)))
      f.write(chr(int(g * 255)))
      f.write(chr(int(b * 255)))

when isMainModule:
  main()
