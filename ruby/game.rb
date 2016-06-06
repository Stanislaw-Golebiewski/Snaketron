require 'rubygems'
require 'gosu'

class MyWindow < Gosu::Window
  def initialize
    super 640, 480, false
    self.caption = 'Hello World!'
  end
end

window = MyWindow.new
window.show

#class Object  -  dla czwysztkich obiektow
#def method_missing(method_name)
	 #kod do wykonania
