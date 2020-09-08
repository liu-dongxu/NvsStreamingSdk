Pod::Spec.new do |s|
  s.name         = "NvsStreaming_Sdk"
  s.version      = "2.16.1"
  s.summary      = "Meishe SDK"
  s.description  = <<-DESC
                     This is Meishe SDK
                   DESC

  s.homepage     = "https://www.meishesdk.com"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "liu-dongxu" => "liu_dongxu@cdv.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/liu-dongxu/NvsStreamingSdk.git", :tag => s.version}
  s.source_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.public_header_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.ios.vendored_frameworks = "lib/**/NvStreamingSdkCore.framework"
  s.requires_arc       = true
  s.xcconfig = {"ENABLE_BITCODE" => "NO"}
end
