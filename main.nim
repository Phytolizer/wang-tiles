const
  WIDTH = 64
  HEIGHT = 64

proc main =
  let f = open("output.ppm", fmWrite)
  defer: f.close()

when isMainModule:
  main()
