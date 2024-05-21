local steakeater = require("libsteakeater")

local result = steakeater.calibrate(100, 102, 150, 0)
print("Calibration success: " .. tostring(result))

local result2, err2 = steakeater.forward()
print("Forward success: " .. tostring(result2))
if not result2 then
    print(err2)
end