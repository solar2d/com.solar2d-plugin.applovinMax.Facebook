local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = {"FacebookAdapter"},
		frameworks = { 'Accounts' ,"FBAudienceNetwork", 'FBSDKCoreKit',  'FBSDKLoginKit', 'FBSDKShareKit', 'FBSDKCoreKit_Basics', "FBAEMKit", "Accelerate", "FBSDKGamingServicesKit", "FBSDKShareKit"},
		frameworksOptional = {},
		delegates = { },
		usesSwift = true,
	},
}

return metadata
