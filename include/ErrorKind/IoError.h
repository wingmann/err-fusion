#ifndef WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H

namespace Wingmann::ErrFusion::ErrorKind
{
	enum class IoError
	{
		NotFound,
		PermissionDenied,
		ConnectionRefused,
		ConnectionReset,
		HostUnreachable,
		NetworkUnreachable,
		ConnectionAborted,
		NotConnected,
		AddrInUse,
		AddrNotAvailable,
		NetworkDown,
		BrokenPipe,
		AlreadyExists,
		WouldBlock,
		NotADirectory,
		IsADirectory,
		DirectoryNotEmpty,
		ReadOnlyFilesystem,
		FilesystemLoop,
		StaleNetworkFileHandle,
		InvalidInput,
		InvalidData,
		TimedOut,
		WriteZero,
		StorageFull,
		NotSeekable,
		FilesystemQuotaExceeded,
		FileTooLarge,
		ResourceBusy,
		ExecutableFileBusy,
		Deadlock,
		CrossesDevices,
		TooManyLinks,
		InvalidFilename,
		ArgumentListTooLong,
		Interrupted,
		Unsupported,
		UnexpectedEof,
		OutOfMemory,
		Other
	};
}

#endif // WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
