Pod::Spec.new do |s|


  #名称
  s.name         = 'MiniProgramSDK'

  #版本号
  s.version      = '1.2.0'

  #简介
  s.summary      = '小程序平台，在iOS项目中加载微信小程序'

 
  #项目主页地址
  s.homepage     = 'https://github.com/meifenglin/MiniProgramSDK'


  #许可证
  s.license      = { :type => 'MIT' }


  #作者
  s.author             = { 'meifenglin' => 'mfl_617@163.com' }


  #支持最小系统版本
  s.platform     = :ios, '10.0'

  #资源文件路径
  s.resources = 'Resources/MPRes.bundle'

  #项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
  s.source       = { :git => 'https://github.com/meifenglin/MiniProgram.git', :tag => s.version }


  #需要包含的源文件 
  s.source_files  = 'Framework/MiniProgram.framework/Headers/*.{h}'


  #SDK路径
  s.vendored_frameworks = 'Framework/MiniProgram.framework'


  #SDK头文件路径
  s.public_header_files = 'Framework/MiniProgram.framework/Headers/MiniProgram.h'


  #依赖库
  s.frameworks = "Foundation", "AVFoundation", "CFNetwork", "CoreBluetooth", "CoreGraphics", "CoreLocation", "JavaScriptCore", "Security", "CoreTelephony", "SystemConfiguration"


  #是否需要支持ARC
  s.requires_arc = true

  s.xcconfig = {
    'VALID_ARCHS' =>  'arm64 x86_64',
  }

  #依赖的第三方库
  s.dependency "AFNetworking", "~> 3.2.1"
  s.dependency "ZipArchive", "~> 1.4.0"
  s.dependency "Masonry", "~> 1.1.0"

end
