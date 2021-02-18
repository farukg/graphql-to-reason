module type SchemaConfig = {
  module Scalars: {
    type id;
    type gitSSHRemote;
    type gitTimestamp;
    type hTML;
    type x509Certificate;
    type gitObjectID;
    type date;
    type dateTime;
    type uRI;
  };
  type resolver('parent, 'payload, 'fieldType, 'result);
  type directiveResolver('payload);
};
module MakeSchema = (Config: SchemaConfig) => {
  include Config.Scalars;
  type rootResolver('payload, 'fieldType, 'result) =
    Config.resolver(unit, 'payload, 'fieldType, 'result);
  type directiveResolver('payload) = Config.directiveResolver('payload);
  type pullRequestTimelineItemsItemType = [
    | `ADDED_TO_PROJECT_EVENT
    | `ASSIGNED_EVENT
    | `BASE_REF_CHANGED_EVENT
    | `BASE_REF_FORCE_PUSHED_EVENT
    | `CLOSED_EVENT
    | `COMMENT_DELETED_EVENT
    | `CONVERTED_NOTE_TO_ISSUE_EVENT
    | `CROSS_REFERENCED_EVENT
    | `DEMILESTONED_EVENT
    | `DEPLOYED_EVENT
    | `DEPLOYMENT_ENVIRONMENT_CHANGED_EVENT
    | `HEAD_REF_DELETED_EVENT
    | `HEAD_REF_FORCE_PUSHED_EVENT
    | `HEAD_REF_RESTORED_EVENT
    | `ISSUE_COMMENT
    | `LABELED_EVENT
    | `LOCKED_EVENT
    | `MENTIONED_EVENT
    | `MERGED_EVENT
    | `MILESTONED_EVENT
    | `MOVED_COLUMNS_IN_PROJECT_EVENT
    | `PULL_REQUEST_COMMIT
    | `PULL_REQUEST_COMMIT_COMMENT_THREAD
    | `PULL_REQUEST_REVIEW
    | `PULL_REQUEST_REVIEW_THREAD
    | `PULL_REQUEST_REVISION_MARKER
    | `REFERENCED_EVENT
    | `REMOVED_FROM_PROJECT_EVENT
    | `RENAMED_TITLE_EVENT
    | `REOPENED_EVENT
    | `REVIEW_DISMISSED_EVENT
    | `REVIEW_REQUESTED_EVENT
    | `REVIEW_REQUEST_REMOVED_EVENT
    | `SUBSCRIBED_EVENT
    | `UNASSIGNED_EVENT
    | `UNLABELED_EVENT
    | `UNLOCKED_EVENT
    | `UNSUBSCRIBED_EVENT
  ]
  and projectCardArchivedState = [ | `ARCHIVED | `NOT_ARCHIVED]
  and pullRequestReviewEvent = [
    | `APPROVE
    | `COMMENT
    | `DISMISS
    | `REQUEST_CHANGES
  ]
  and issueOrderField = [ | `COMMENTS | `CREATED_AT | `UPDATED_AT]
  and repositoryContributionType = [
    | `COMMIT
    | `ISSUE
    | `PULL_REQUEST
    | `PULL_REQUEST_REVIEW
    | `REPOSITORY
  ]
  and projectColumnPurpose = [ | `DONE | `IN_PROGRESS | `TODO]
  and collaboratorAffiliation = [ | `ALL | `DIRECT | `OUTSIDE]
  and teamMemberOrderField = [ | `CREATED_AT | `LOGIN]
  and teamOrderField = [ | `NAME]
  and gistPrivacy = [ | `ALL | `PUBLIC | `SECRET]
  and issueState = [ | `CLOSED | `OPEN]
  and pullRequestReviewCommentState = [ | `PENDING | `SUBMITTED]
  and teamRole = [ | `ADMIN | `MEMBER]
  and reactionOrderField = [ | `CREATED_AT]
  and pullRequestReviewState = [
    | `APPROVED
    | `CHANGES_REQUESTED
    | `COMMENTED
    | `DISMISSED
    | `PENDING
  ]
  and topicSuggestionDeclineReason = [
    | `NOT_RELEVANT
    | `PERSONAL_PREFERENCE
    | `TOO_GENERAL
    | `TOO_SPECIFIC
  ]
  and milestoneState = [ | `CLOSED | `OPEN]
  and reactionContent = [
    | `CONFUSED
    | `HEART
    | `HOORAY
    | `LAUGH
    | `THUMBS_DOWN
    | `THUMBS_UP
  ]
  and gitSignatureState = [
    | `BAD_CERT
    | `BAD_EMAIL
    | `EXPIRED_KEY
    | `GPGVERIFY_ERROR
    | `GPGVERIFY_UNAVAILABLE
    | `INVALID
    | `MALFORMED_SIG
    | `NOT_SIGNING_KEY
    | `NO_USER
    | `OCSP_ERROR
    | `OCSP_PENDING
    | `OCSP_REVOKED
    | `UNKNOWN_KEY
    | `UNKNOWN_SIG_TYPE
    | `UNSIGNED
    | `UNVERIFIED_EMAIL
    | `VALID
  ]
  and repositoryAffiliation = [
    | `COLLABORATOR
    | `ORGANIZATION_MEMBER
    | `OWNER
  ]
  and orderDirection = [ | `ASC | `DESC]
  and refOrderField = [ | `ALPHABETICAL | `TAG_COMMIT_DATE]
  and repositoryCollaboratorAffiliation = [ | `ALL | `OUTSIDE]
  and repositoryPermission = [ | `ADMIN | `READ | `WRITE]
  and repositoryOrderField = [
    | `CREATED_AT
    | `NAME
    | `PUSHED_AT
    | `STARGAZERS
    | `UPDATED_AT
  ]
  and pullRequestPubSubTopic = [
    | `HEAD_REF
    | `MARKASREAD
    | `STATE
    | `TIMELINE
    | `UPDATED
  ]
  and teamPrivacy = [ | `SECRET | `VISIBLE]
  and teamMemberRole = [ | `MAINTAINER | `MEMBER]
  and releaseOrderField = [ | `CREATED_AT | `NAME]
  and issuePubSubTopic = [ | `MARKASREAD | `STATE | `TIMELINE | `UPDATED]
  and mergeableState = [ | `CONFLICTING | `MERGEABLE | `UNKNOWN]
  and organizationInvitationType = [ | `EMAIL | `USER]
  and repositoryPrivacy = [ | `PRIVATE | `PUBLIC]
  and starOrderField = [ | `STARRED_AT]
  and pullRequestOrderField = [ | `CREATED_AT | `UPDATED_AT]
  and projectOrderField = [ | `CREATED_AT | `NAME | `UPDATED_AT]
  and projectState = [ | `CLOSED | `OPEN]
  and defaultRepositoryPermissionField = [ | `ADMIN | `NONE | `READ | `WRITE]
  and teamRepositoryOrderField = [
    | `CREATED_AT
    | `NAME
    | `PERMISSION
    | `PUSHED_AT
    | `STARGAZERS
    | `UPDATED_AT
  ]
  and deploymentStatusState = [
    | `ERROR
    | `FAILURE
    | `INACTIVE
    | `PENDING
    | `SUCCESS
  ]
  and repositoryLockReason = [ | `BILLING | `MIGRATING | `MOVING | `RENAME]
  and issueTimelineItemsItemType = [
    | `ADDED_TO_PROJECT_EVENT
    | `ASSIGNED_EVENT
    | `CLOSED_EVENT
    | `COMMENT_DELETED_EVENT
    | `CONVERTED_NOTE_TO_ISSUE_EVENT
    | `CROSS_REFERENCED_EVENT
    | `DEMILESTONED_EVENT
    | `ISSUE_COMMENT
    | `LABELED_EVENT
    | `LOCKED_EVENT
    | `MENTIONED_EVENT
    | `MILESTONED_EVENT
    | `MOVED_COLUMNS_IN_PROJECT_EVENT
    | `REFERENCED_EVENT
    | `REMOVED_FROM_PROJECT_EVENT
    | `RENAMED_TITLE_EVENT
    | `REOPENED_EVENT
    | `SUBSCRIBED_EVENT
    | `UNASSIGNED_EVENT
    | `UNLABELED_EVENT
    | `UNLOCKED_EVENT
    | `UNSUBSCRIBED_EVENT
  ]
  and gistOrderField = [ | `CREATED_AT | `PUSHED_AT | `UPDATED_AT]
  and projectCardState = [ | `CONTENT_ONLY | `NOTE_ONLY | `REDACTED]
  and organizationInvitationRole = [
    | `ADMIN
    | `BILLING_MANAGER
    | `DIRECT_MEMBER
    | `REINSTATE
  ]
  and commentCannotUpdateReason = [
    | `INSUFFICIENT_ACCESS
    | `LOCKED
    | `LOGIN_REQUIRED
    | `MAINTENANCE
    | `VERIFIED_EMAIL_REQUIRED
  ]
  and searchType = [ | `ISSUE | `REPOSITORY | `USER]
  and teamMembershipType = [ | `ALL | `CHILD_TEAM | `IMMEDIATE]
  and statusState = [ | `ERROR | `EXPECTED | `FAILURE | `PENDING | `SUCCESS]
  and subscriptionState = [ | `IGNORED | `SUBSCRIBED | `UNSUBSCRIBED]
  and languageOrderField = [ | `SIZE]
  and deploymentState = [
    | `ABANDONED
    | `ACTIVE
    | `DESTROYED
    | `ERROR
    | `FAILURE
    | `INACTIVE
    | `PENDING
  ]
  and pullRequestState = [ | `CLOSED | `MERGED | `OPEN]
  and lockReason = [ | `OFF_TOPIC | `RESOLVED | `SPAM | `TOO_HEATED]
  and commentAuthorAssociation = [
    | `COLLABORATOR
    | `CONTRIBUTOR
    | `FIRST_TIMER
    | `FIRST_TIME_CONTRIBUTOR
    | `MEMBER
    | `NONE
    | `OWNER
  ]
  and milestoneOrderField = [
    | `CREATED_AT
    | `DUE_DATE
    | `NUMBER
    | `UPDATED_AT
  ];
  type lockLockableInput = {
    clientMutationId: option(string),
    lockReason: option(lockReason),
    lockableId: string,
  }
  and addReactionInput = {
    clientMutationId: option(string),
    content: reactionContent,
    subjectId: string,
  }
  and deletePullRequestReviewInput = {
    clientMutationId: option(string),
    pullRequestReviewId: string,
  }
  and declineTopicSuggestionInput = {
    clientMutationId: option(string),
    name: string,
    reason: topicSuggestionDeclineReason,
    repositoryId: string,
  }
  and reactionOrder = {
    direction: orderDirection,
    field: reactionOrderField,
  }
  and deleteBranchProtectionRuleInput = {
    branchProtectionRuleId: string,
    clientMutationId: option(string),
  }
  and pullRequestOrder = {
    direction: orderDirection,
    field: pullRequestOrderField,
  }
  and addProjectColumnInput = {
    clientMutationId: option(string),
    name: string,
    projectId: string,
  }
  and createBranchProtectionRuleInput = {
    clientMutationId: option(string),
    dismissesStaleReviews: option(bool),
    isAdminEnforced: option(bool),
    pattern: string,
    pushActorIds: option(array(string)),
    repositoryId: string,
    requiredApprovingReviewCount: option(int),
    requiredStatusCheckContexts: option(array(string)),
    requiresApprovingReviews: option(bool),
    requiresCodeOwnerReviews: option(bool),
    requiresCommitSignatures: option(bool),
    requiresStatusChecks: option(bool),
    requiresStrictStatusChecks: option(bool),
    restrictsPushes: option(bool),
    restrictsReviewDismissals: option(bool),
    reviewDismissalActorIds: option(array(string)),
  }
  and updatePullRequestReviewInput = {
    body: string,
    clientMutationId: option(string),
    pullRequestReviewId: string,
  }
  and addPullRequestReviewInput = {
    body: option(string),
    clientMutationId: option(string),
    comments: option(array(option(draftPullRequestReviewComment))),
    commitOID: option(gitObjectID),
    event: option(pullRequestReviewEvent),
    pullRequestId: string,
  }
  and updateProjectInput = {
    body: option(string),
    clientMutationId: option(string),
    name: option(string),
    projectId: string,
    public: option(bool),
    state: option(projectState),
  }
  and deleteProjectCardInput = {
    cardId: string,
    clientMutationId: option(string),
  }
  and moveProjectColumnInput = {
    afterColumnId: option(string),
    clientMutationId: option(string),
    columnId: string,
  }
  and updatePullRequestReviewCommentInput = {
    body: string,
    clientMutationId: option(string),
    pullRequestReviewCommentId: string,
  }
  and submitPullRequestReviewInput = {
    body: option(string),
    clientMutationId: option(string),
    event: pullRequestReviewEvent,
    pullRequestReviewId: string,
  }
  and removeStarInput = {
    clientMutationId: option(string),
    starrableId: string,
  }
  and acceptTopicSuggestionInput = {
    clientMutationId: option(string),
    name: string,
    repositoryId: string,
  }
  and addPullRequestReviewCommentInput = {
    body: string,
    clientMutationId: option(string),
    commitOID: option(gitObjectID),
    inReplyTo: option(string),
    path: option(string),
    position: option(int),
    pullRequestReviewId: string,
  }
  and issueOrder = {
    direction: orderDirection,
    field: issueOrderField,
  }
  and updateSubscriptionInput = {
    clientMutationId: option(string),
    state: subscriptionState,
    subscribableId: string,
  }
  and projectOrder = {
    direction: orderDirection,
    field: projectOrderField,
  }
  and releaseOrder = {
    direction: orderDirection,
    field: releaseOrderField,
  }
  and unlockLockableInput = {
    clientMutationId: option(string),
    lockableId: string,
  }
  and addProjectCardInput = {
    clientMutationId: option(string),
    contentId: option(string),
    note: option(string),
    projectColumnId: string,
  }
  and draftPullRequestReviewComment = {
    body: string,
    path: string,
    position: int,
  }
  and createProjectInput = {
    body: option(string),
    clientMutationId: option(string),
    name: string,
    ownerId: string,
  }
  and repositoryOrder = {
    direction: orderDirection,
    field: repositoryOrderField,
  }
  and teamMemberOrder = {
    direction: orderDirection,
    field: teamMemberOrderField,
  }
  and addStarInput = {
    clientMutationId: option(string),
    starrableId: string,
  }
  and requestReviewsInput = {
    clientMutationId: option(string),
    pullRequestId: string,
    teamIds: option(array(string)),
    union: option(bool),
    userIds: option(array(string)),
  }
  and moveProjectCardInput = {
    afterCardId: option(string),
    cardId: string,
    clientMutationId: option(string),
    columnId: string,
  }
  and milestoneOrder = {
    direction: orderDirection,
    field: milestoneOrderField,
  }
  and updateBranchProtectionRuleInput = {
    branchProtectionRuleId: string,
    clientMutationId: option(string),
    dismissesStaleReviews: option(bool),
    isAdminEnforced: option(bool),
    pattern: option(string),
    pushActorIds: option(array(string)),
    requiredApprovingReviewCount: option(int),
    requiredStatusCheckContexts: option(array(string)),
    requiresApprovingReviews: option(bool),
    requiresCodeOwnerReviews: option(bool),
    requiresCommitSignatures: option(bool),
    requiresStatusChecks: option(bool),
    requiresStrictStatusChecks: option(bool),
    restrictsPushes: option(bool),
    restrictsReviewDismissals: option(bool),
    reviewDismissalActorIds: option(array(string)),
  }
  and teamRepositoryOrder = {
    direction: orderDirection,
    field: teamRepositoryOrderField,
  }
  and removeOutsideCollaboratorInput = {
    clientMutationId: option(string),
    organizationId: string,
    userId: string,
  }
  and updateProjectColumnInput = {
    clientMutationId: option(string),
    name: string,
    projectColumnId: string,
  }
  and removeReactionInput = {
    clientMutationId: option(string),
    content: reactionContent,
    subjectId: string,
  }
  and updateProjectCardInput = {
    clientMutationId: option(string),
    isArchived: option(bool),
    note: option(string),
    projectCardId: string,
  }
  and updateTopicsInput = {
    clientMutationId: option(string),
    repositoryId: string,
    topicNames: array(string),
  }
  and commitAuthor = {
    emails: option(array(string)),
    id: option(string),
  }
  and deleteProjectInput = {
    clientMutationId: option(string),
    projectId: string,
  }
  and refOrder = {
    direction: orderDirection,
    field: refOrderField,
  }
  and teamOrder = {
    direction: orderDirection,
    field: teamOrderField,
  }
  and gistOrder = {
    direction: orderDirection,
    field: gistOrderField,
  }
  and dismissPullRequestReviewInput = {
    clientMutationId: option(string),
    message: string,
    pullRequestReviewId: string,
  }
  and addCommentInput = {
    body: string,
    clientMutationId: option(string),
    subjectId: string,
  }
  and deleteProjectColumnInput = {
    clientMutationId: option(string),
    columnId: string,
  }
  and languageOrder = {
    direction: orderDirection,
    field: languageOrderField,
  }
  and starOrder = {
    direction: orderDirection,
    field: starOrderField,
  };
  type milestoneItem
  and reviewDismissalAllowanceActor
  and requestedReviewer
  and projectCardItem
  and referencedSubject
  and issueTimelineItems
  and pullRequestTimelineItem
  and issueTimelineItem
  and renamedTitleSubject
  and closer
  and pushAllowanceActor
  and issueOrPullRequest
  and pullRequestTimelineItems
  and collectionItemContent
  and searchResultItem
  and actor = {
    .
    "avatarUrl": uRI,
    "login": string,
    "resourcePath": uRI,
    "url": uRI,
  }
  and subscribable = {
    .
    "id": string,
    "viewerCanSubscribe": bool,
    "viewerSubscription": option(subscriptionState),
  }
  and gitObject = {
    .
    "abbreviatedOid": string,
    "commitResourcePath": uRI,
    "commitUrl": uRI,
    "id": string,
    "oid": gitObjectID,
    "repository": repository,
  }
  and closable = {
    .
    "closed": bool,
    "closedAt": option(dateTime),
  }
  and lockable = {
    .
    "activeLockReason": option(lockReason),
    "locked": bool,
  }
  and assignable = {. "assignees": userConnection}
  and deletable = {. "viewerCanDelete": bool}
  and reactable = {
    .
    "databaseId": option(int),
    "id": string,
    "reactionGroups": option(array(reactionGroup)),
    "reactions": reactionConnection,
    "viewerCanReact": bool,
  }
  and registryPackageOwner = {. "id": string}
  and registryPackageSearch = {. "id": string}
  and uniformResourceLocatable = {
    .
    "resourcePath": uRI,
    "url": uRI,
  }
  and repositoryNode = {. "repository": repository}
  and node = {. "id": string}
  and projectOwner = {
    .
    "id": string,
    "project": option(project),
    "projects": projectConnection,
    "projectsResourcePath": uRI,
    "projectsUrl": uRI,
    "viewerCanCreateProjects": bool,
  }
  and repositoryOwner = {
    .
    "avatarUrl": uRI,
    "id": string,
    "login": string,
    "pinnedRepositories": repositoryConnection,
    "repositories": repositoryConnection,
    "repository": option(repository),
    "resourcePath": uRI,
    "url": uRI,
  }
  and starrable = {
    .
    "id": string,
    "stargazers": stargazerConnection,
    "viewerHasStarred": bool,
  }
  and gitSignature = {
    .
    "email": string,
    "isValid": bool,
    "payload": string,
    "signature": string,
    "signer": option(user),
    "state": gitSignatureState,
    "wasSignedByGitHub": bool,
  }
  and updatableComment = {
    .
    "viewerCannotUpdateReasons": array(commentCannotUpdateReason),
  }
  and comment = {
    .
    "author": option(actor),
    "authorAssociation": commentAuthorAssociation,
    "body": string,
    "bodyHTML": hTML,
    "bodyText": string,
    "createdAt": dateTime,
    "createdViaEmail": bool,
    "editor": option(actor),
    "id": string,
    "includesCreatedEdit": bool,
    "lastEditedAt": option(dateTime),
    "publishedAt": option(dateTime),
    "updatedAt": dateTime,
    "userContentEdits": option(userContentEditConnection),
    "viewerDidAuthor": bool,
  }
  and labelable = {. "labels": option(labelConnection)}
  and repositoryInfo = {
    .
    "createdAt": dateTime,
    "description": option(string),
    "descriptionHTML": hTML,
    "forkCount": int,
    "hasIssuesEnabled": bool,
    "hasWikiEnabled": bool,
    "homepageUrl": option(uRI),
    "isArchived": bool,
    "isFork": bool,
    "isLocked": bool,
    "isMirror": bool,
    "isPrivate": bool,
    "licenseInfo": option(license),
    "lockReason": option(repositoryLockReason),
    "mirrorUrl": option(uRI),
    "name": string,
    "nameWithOwner": string,
    "owner": repositoryOwner,
    "pushedAt": option(dateTime),
    "resourcePath": uRI,
    "shortDescriptionHTML": hTML,
    "updatedAt": dateTime,
    "url": uRI,
  }
  and updatable = {. "viewerCanUpdate": bool}
  and reactingUserConnection = {
    edges: option(array(option(reactingUserEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and gitActor = {
    avatarUrl: uRI,
    date: option(gitTimestamp),
    email: option(string),
    name: option(string),
    user: option(user),
  }
  and pushAllowance = {
    actor: option(pushAllowanceActor),
    branchProtectionRule: option(branchProtectionRule),
    id: string,
    protectedBranch,
  }
  and reviewDismissalAllowance = {
    actor: option(reviewDismissalAllowanceActor),
    branchProtectionRule: option(branchProtectionRule),
    id: string,
    protectedBranch,
  }
  and projectEdge = {
    cursor: string,
    node: option(project),
  }
  and convertedNoteToIssueEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and labeledEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    label,
    labelable,
  }
  and app = {
    createdAt: dateTime,
    databaseId: option(int),
    description: option(string),
    id: string,
    logoBackgroundColor: string,
    logoUrl: uRI,
    name: string,
    slug: string,
    updatedAt: dateTime,
    url: uRI,
  }
  and status = {
    commit: option(commit),
    context: option(statusContext),
    contexts: array(statusContext),
    id: string,
    state: statusState,
  }
  and pageInfo = {
    endCursor: option(string),
    hasNextPage: bool,
    hasPreviousPage: bool,
    startCursor: option(string),
  }
  and issueCommentEdge = {
    cursor: string,
    node: option(issueComment),
  }
  and userContentEditEdge = {
    cursor: string,
    node: option(userContentEdit),
  }
  and organizationConnection = {
    edges: option(array(option(organizationEdge))),
    nodes: option(array(option(organization))),
    pageInfo,
    totalCount: int,
  }
  and releaseConnection = {
    edges: option(array(option(releaseEdge))),
    nodes: option(array(option(release))),
    pageInfo,
    totalCount: int,
  }
  and reviewRequestConnection = {
    edges: option(array(option(reviewRequestEdge))),
    nodes: option(array(option(reviewRequest))),
    pageInfo,
    totalCount: int,
  }
  and pullRequestCommit = {
    commit,
    id: string,
    pullRequest,
    resourcePath: uRI,
    url: uRI,
  }
  and pullRequestReviewConnection = {
    edges: option(array(option(pullRequestReviewEdge))),
    nodes: option(array(option(pullRequestReview))),
    pageInfo,
    totalCount: int,
  }
  and addPullRequestReviewCommentPayload = {
    clientMutationId: option(string),
    comment: pullRequestReviewComment,
    commentEdge: pullRequestReviewCommentEdge,
  }
  and externalIdentityConnection = {
    edges: option(array(option(externalIdentityEdge))),
    nodes: option(array(option(externalIdentity))),
    pageInfo,
    totalCount: int,
  }
  and commitCommentEdge = {
    cursor: string,
    node: option(commitComment),
  }
  and assignedEvent = {
    actor: option(actor),
    assignable,
    createdAt: dateTime,
    id: string,
    user: option(user),
  }
  and projectColumnConnection = {
    edges: option(array(option(projectColumnEdge))),
    nodes: option(array(option(projectColumn))),
    pageInfo,
    totalCount: int,
  }
  and statusContext = {
    commit: option(commit),
    context: string,
    createdAt: dateTime,
    creator: option(actor),
    description: option(string),
    id: string,
    state: statusState,
    targetUrl: option(uRI),
  }
  and gpgSignature = {
    email: string,
    isValid: bool,
    keyId: option(string),
    payload: string,
    signature: string,
    signer: option(user),
    state: gitSignatureState,
    wasSignedByGitHub: bool,
  }
  and commitConnection = {
    edges: option(array(option(commitEdge))),
    nodes: option(array(option(commit))),
    pageInfo,
    totalCount: int,
  }
  and externalIdentityEdge = {
    cursor: string,
    node: option(externalIdentity),
  }
  and bot = {
    avatarUrl: uRI,
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
    login: string,
    resourcePath: uRI,
    updatedAt: dateTime,
    url: uRI,
  }
  and protectedBranchConnection = {
    edges: option(array(option(protectedBranchEdge))),
    nodes: option(array(option(protectedBranch))),
    pageInfo,
    totalCount: int,
  }
  and pullRequestTimelineItemEdge = {
    cursor: string,
    node: option(pullRequestTimelineItem),
  }
  and projectColumnEdge = {
    cursor: string,
    node: option(projectColumn),
  }
  and pullRequestReview = {
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    comments: pullRequestReviewCommentConnection,
    commit: option(commit),
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    editor: option(actor),
    id: string,
    includesCreatedEdit: bool,
    lastEditedAt: option(dateTime),
    onBehalfOf: teamConnection,
    publishedAt: option(dateTime),
    pullRequest,
    repository,
    resourcePath: uRI,
    state: pullRequestReviewState,
    submittedAt: option(dateTime),
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanDelete: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
  }
  and publicKey = {
    id: string,
    key: string,
  }
  and releaseAssetConnection = {
    edges: option(array(option(releaseAssetEdge))),
    nodes: option(array(option(releaseAsset))),
    pageInfo,
    totalCount: int,
  }
  and branchProtectionRuleConnection = {
    edges: option(array(option(branchProtectionRuleEdge))),
    nodes: option(array(option(branchProtectionRule))),
    pageInfo,
    totalCount: int,
  }
  and releaseAsset = {
    contentType: string,
    createdAt: dateTime,
    downloadCount: int,
    downloadUrl: uRI,
    id: string,
    name: string,
    release: option(release),
    size: int,
    updatedAt: dateTime,
    uploadedBy: user,
    url: uRI,
  }
  and deployKeyConnection = {
    edges: option(array(option(deployKeyEdge))),
    nodes: option(array(option(deployKey))),
    pageInfo,
    totalCount: int,
  }
  and pullRequestCommitEdge = {
    cursor: string,
    node: option(pullRequestCommit),
  }
  and removeStarPayload = {
    clientMutationId: option(string),
    starrable,
  }
  and suggestedReviewer = {
    isAuthor: bool,
    isCommenter: bool,
    reviewer: user,
  }
  and reviewRequest = {
    databaseId: option(int),
    id: string,
    pullRequest,
    requestedReviewer: option(requestedReviewer),
  }
  and tree = {
    abbreviatedOid: string,
    commitResourcePath: uRI,
    commitUrl: uRI,
    entries: option(array(treeEntry)),
    id: string,
    oid: gitObjectID,
    repository,
  }
  and searchResultItemConnection = {
    codeCount: int,
    edges: option(array(option(searchResultItemEdge))),
    issueCount: int,
    nodes: option(array(option(searchResultItem))),
    pageInfo,
    repositoryCount: int,
    userCount: int,
    wikiCount: int,
  }
  and stargazerConnection = {
    edges: option(array(option(stargazerEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and languageEdge = {
    cursor: string,
    node: language,
    size: int,
  }
  and issueCommentConnection = {
    edges: option(array(option(issueCommentEdge))),
    nodes: option(array(option(issueComment))),
    pageInfo,
    totalCount: int,
  }
  and tag = {
    abbreviatedOid: string,
    commitResourcePath: uRI,
    commitUrl: uRI,
    id: string,
    message: option(string),
    name: string,
    oid: gitObjectID,
    repository,
    tagger: option(gitActor),
    target: gitObject,
  }
  and addPullRequestReviewPayload = {
    clientMutationId: option(string),
    pullRequestReview,
    reviewEdge: pullRequestReviewEdge,
  }
  and updateProjectColumnPayload = {
    clientMutationId: option(string),
    projectColumn,
  }
  and refConnection = {
    edges: option(array(option(refEdge))),
    nodes: option(array(option(ref))),
    pageInfo,
    totalCount: int,
  }
  and issueTimelineItemEdge = {
    cursor: string,
    node: option(issueTimelineItem),
  }
  and crossReferencedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    isCrossRepository: bool,
    referencedAt: dateTime,
    resourcePath: uRI,
    source: referencedSubject,
    target: referencedSubject,
    url: uRI,
    willCloseTarget: bool,
  }
  and reaction = {
    content: reactionContent,
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
    reactable,
    user: option(user),
  }
  and addProjectCardPayload = {
    cardEdge: projectCardEdge,
    clientMutationId: option(string),
    projectColumn: project,
  }
  and gistComment = {
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    editor: option(actor),
    gist,
    id: string,
    includesCreatedEdit: bool,
    lastEditedAt: option(dateTime),
    publishedAt: option(dateTime),
    updatedAt: dateTime,
    userContentEdits: option(userContentEditConnection),
    viewerCanDelete: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
  }
  and organizationInvitationEdge = {
    cursor: string,
    node: option(organizationInvitation),
  }
  and repositoryInvitationEdge = {
    cursor: string,
    node: option(repositoryInvitation),
  }
  and textMatchHighlight = {
    beginIndice: int,
    endIndice: int,
    text: string,
  }
  and projectCard = {
    column: option(projectColumn),
    content: option(projectCardItem),
    createdAt: dateTime,
    creator: option(actor),
    databaseId: option(int),
    id: string,
    isArchived: bool,
    note: option(string),
    project,
    resourcePath: uRI,
    state: option(projectCardState),
    updatedAt: dateTime,
    url: uRI,
  }
  and languageConnection = {
    edges: option(array(option(languageEdge))),
    nodes: option(array(option(language))),
    pageInfo,
    totalCount: int,
    totalSize: int,
  }
  and topicEdge = {
    cursor: string,
    node: option(topic),
  }
  and refEdge = {
    cursor: string,
    node: option(ref),
  }
  and marketplaceListing = {
    app: option(app),
    companyUrl: option(uRI),
    configurationResourcePath: uRI,
    configurationUrl: uRI,
    documentationUrl: option(uRI),
    extendedDescription: option(string),
    extendedDescriptionHTML: hTML,
    fullDescription: string,
    fullDescriptionHTML: hTML,
    hasApprovalBeenRequested: bool,
    hasPublishedFreeTrialPlans: bool,
    hasTermsOfService: bool,
    howItWorks: option(string),
    howItWorksHTML: hTML,
    id: string,
    installationUrl: option(uRI),
    installedForViewer: bool,
    isApproved: bool,
    isDelisted: bool,
    isDraft: bool,
    isPaid: bool,
    isRejected: bool,
    logoBackgroundColor: string,
    logoUrl: option(uRI),
    name: string,
    normalizedShortDescription: string,
    pricingUrl: option(uRI),
    primaryCategory: marketplaceCategory,
    privacyPolicyUrl: uRI,
    resourcePath: uRI,
    screenshotUrls: array(option(string)),
    secondaryCategory: option(marketplaceCategory),
    shortDescription: string,
    slug: string,
    statusUrl: option(uRI),
    supportEmail: option(string),
    supportUrl: uRI,
    termsOfServiceUrl: option(uRI),
    url: uRI,
    viewerCanAddPlans: bool,
    viewerCanApprove: bool,
    viewerCanDelist: bool,
    viewerCanEdit: bool,
    viewerCanEditCategories: bool,
    viewerCanEditPlans: bool,
    viewerCanRedraft: bool,
    viewerCanReject: bool,
    viewerCanRequestApproval: bool,
    viewerHasPurchased: bool,
    viewerHasPurchasedForAllOrganizations: bool,
    viewerIsListingAdmin: bool,
  }
  and commitCommentConnection = {
    edges: option(array(option(commitCommentEdge))),
    nodes: option(array(option(commitComment))),
    pageInfo,
    totalCount: int,
  }
  and pullRequestReviewCommentConnection = {
    edges: option(array(option(pullRequestReviewCommentEdge))),
    nodes: option(array(option(pullRequestReviewComment))),
    pageInfo,
    totalCount: int,
  }
  and labelEdge = {
    cursor: string,
    node: option(label),
  }
  and createProjectPayload = {
    clientMutationId: option(string),
    project,
  }
  and treeEntry = {
    mode: int,
    name: string,
    object_: option(gitObject),
    oid: gitObjectID,
    repository,
    type_: string,
  }
  and blameRange = {
    age: int,
    commit,
    endingLine: int,
    startingLine: int,
  }
  and marketplaceCategory = {
    description: option(string),
    howItWorks: option(string),
    id: string,
    name: string,
    primaryListingCount: int,
    resourcePath: uRI,
    secondaryListingCount: int,
    slug: string,
    url: uRI,
  }
  and baseRefForcePushedEvent = {
    actor: option(actor),
    afterCommit: option(commit),
    beforeCommit: option(commit),
    createdAt: dateTime,
    id: string,
    pullRequest,
    ref: option(ref),
  }
  and commitEdge = {
    cursor: string,
    node: option(commit),
  }
  and teamRepositoryConnection = {
    edges: option(array(option(teamRepositoryEdge))),
    nodes: option(array(option(repository))),
    pageInfo,
    totalCount: int,
  }
  and teamEdge = {
    cursor: string,
    node: option(team),
  }
  and commitHistoryConnection = {
    edges: option(array(option(commitEdge))),
    nodes: option(array(option(commit))),
    pageInfo,
    totalCount: int,
  }
  and userConnection = {
    edges: option(array(option(userEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and gistEdge = {
    cursor: string,
    node: option(gist),
  }
  and teamRepositoryEdge = {
    cursor: string,
    node: repository,
    permission: repositoryPermission,
  }
  and blame = {ranges: array(blameRange)}
  and branchProtectionRule = {
    branchProtectionRuleConflicts: branchProtectionRuleConflictConnection,
    creator: option(actor),
    databaseId: option(int),
    dismissesStaleReviews: bool,
    id: string,
    isAdminEnforced: bool,
    matchingRefs: refConnection,
    pattern: string,
    pushAllowances: pushAllowanceConnection,
    repository: option(repository),
    requiredApprovingReviewCount: option(int),
    requiredStatusCheckContexts: option(array(option(string))),
    requiresApprovingReviews: bool,
    requiresCommitSignatures: bool,
    requiresStatusChecks: bool,
    requiresStrictStatusChecks: bool,
    restrictsPushes: bool,
    restrictsReviewDismissals: bool,
    reviewDismissalAllowances: reviewDismissalAllowanceConnection,
  }
  and deployment = {
    commit: option(commit),
    createdAt: dateTime,
    creator: option(actor),
    databaseId: option(int),
    description: option(string),
    environment: option(string),
    id: string,
    latestStatus: option(deploymentStatus),
    payload: option(string),
    ref: option(ref),
    repository,
    state: option(deploymentState),
    statuses: option(deploymentStatusConnection),
    task: option(string),
    updatedAt: dateTime,
  }
  and repositoryCollaboratorEdge = {
    cursor: string,
    node: user,
    permission: repositoryPermission,
  }
  and language = {
    color: option(string),
    id: string,
    name: string,
  }
  and deleteProjectPayload = {
    clientMutationId: option(string),
    owner: projectOwner,
  }
  and addStarPayload = {
    clientMutationId: option(string),
    starrable,
  }
  and publicKeyEdge = {
    cursor: string,
    node: option(publicKey),
  }
  and repositoryEdge = {
    cursor: string,
    node: option(repository),
  }
  and deploymentStatusEdge = {
    cursor: string,
    node: option(deploymentStatus),
  }
  and headRefForcePushedEvent = {
    actor: option(actor),
    afterCommit: option(commit),
    beforeCommit: option(commit),
    createdAt: dateTime,
    id: string,
    pullRequest,
    ref: option(ref),
  }
  and organizationIdentityProvider = {
    digestMethod: option(uRI),
    externalIdentities: externalIdentityConnection,
    id: string,
    idpCertificate: option(x509Certificate),
    issuer: option(string),
    organization: option(organization),
    signatureMethod: option(uRI),
    ssoUrl: option(uRI),
  }
  and baseRefChangedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and projectConnection = {
    edges: option(array(option(projectEdge))),
    nodes: option(array(option(project))),
    pageInfo,
    totalCount: int,
  }
  and pullRequestEdge = {
    cursor: string,
    node: option(pullRequest),
  }
  and unassignedEvent = {
    actor: option(actor),
    assignable,
    createdAt: dateTime,
    id: string,
    user: option(user),
  }
  and userContentEdit = {
    createdAt: dateTime,
    deletedAt: option(dateTime),
    deletedBy: option(actor),
    diff: option(string),
    editedAt: dateTime,
    editor: option(actor),
    id: string,
    updatedAt: dateTime,
  }
  and pullRequestTimelineConnection = {
    edges: option(array(option(pullRequestTimelineItemEdge))),
    nodes: option(array(option(pullRequestTimelineItem))),
    pageInfo,
    totalCount: int,
  }
  and addProjectColumnPayload = {
    clientMutationId: option(string),
    columnEdge: projectColumnEdge,
    project,
  }
  and deleteProjectColumnPayload = {
    clientMutationId: option(string),
    deletedColumnId: string,
    project,
  }
  and deploymentEdge = {
    cursor: string,
    node: option(deployment),
  }
  and teamMemberEdge = {
    cursor: string,
    memberAccessResourcePath: uRI,
    memberAccessUrl: uRI,
    node: user,
    role: teamMemberRole,
  }
  and requestReviewsPayload = {
    clientMutationId: option(string),
    pullRequest,
    requestedReviewersEdge: userEdge,
  }
  and headRefRestoredEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    pullRequest,
  }
  and reviewDismissalAllowanceConnection = {
    edges: option(array(option(reviewDismissalAllowanceEdge))),
    nodes: option(array(option(reviewDismissalAllowance))),
    pageInfo,
    totalCount: int,
  }
  and searchResultItemEdge = {
    cursor: string,
    node: option(searchResultItem),
    textMatches: option(array(option(textMatch))),
  }
  and deletePullRequestReviewPayload = {
    clientMutationId: option(string),
    pullRequestReview,
  }
  and renamedTitleEvent = {
    actor: option(actor),
    createdAt: dateTime,
    currentTitle: string,
    id: string,
    previousTitle: string,
    subject: renamedTitleSubject,
  }
  and demilestonedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    milestoneTitle: string,
    subject: milestoneItem,
  }
  and issueComment = {
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    editor: option(actor),
    id: string,
    includesCreatedEdit: bool,
    issue,
    lastEditedAt: option(dateTime),
    publishedAt: option(dateTime),
    pullRequest: option(pullRequest),
    reactionGroups: option(array(reactionGroup)),
    reactions: reactionConnection,
    repository,
    resourcePath: uRI,
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanDelete: bool,
    viewerCanReact: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
  }
  and updateBranchProtectionRulePayload = {
    branchProtectionRule: option(branchProtectionRule),
    clientMutationId: option(string),
  }
  and commitCommentThread = {
    comments: commitCommentConnection,
    commit,
    id: string,
    path: option(string),
    position: option(int),
    repository,
  }
  and removeReactionPayload = {
    clientMutationId: option(string),
    reaction,
    subject: reactable,
  }
  and user = {
    avatarUrl: uRI,
    bio: option(string),
    bioHTML: hTML,
    commitComments: commitCommentConnection,
    company: option(string),
    companyHTML: hTML,
    createdAt: dateTime,
    databaseId: option(int),
    email: string,
    followers: followerConnection,
    following: followingConnection,
    gist: option(gist),
    gistComments: gistCommentConnection,
    gists: gistConnection,
    id: string,
    isBountyHunter: bool,
    isCampusExpert: bool,
    isDeveloperProgramMember: bool,
    isEmployee: bool,
    isHireable: bool,
    isSiteAdmin: bool,
    isViewer: bool,
    issueComments: issueCommentConnection,
    issues: issueConnection,
    location: option(string),
    login: string,
    name: option(string),
    organization: option(organization),
    organizations: organizationConnection,
    pinnedRepositories: repositoryConnection,
    publicKeys: publicKeyConnection,
    pullRequests: pullRequestConnection,
    repositories: repositoryConnection,
    repositoriesContributedTo: repositoryConnection,
    repository: option(repository),
    resourcePath: uRI,
    starredRepositories: starredRepositoryConnection,
    updatedAt: dateTime,
    url: uRI,
    viewerCanFollow: bool,
    viewerIsFollowing: bool,
    watching: repositoryConnection,
    websiteUrl: option(uRI),
  }
  and reactionEdge = {
    cursor: string,
    node: option(reaction),
  }
  and milestonedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    milestoneTitle: string,
    subject: milestoneItem,
  }
  and ref = {
    associatedPullRequests: pullRequestConnection,
    id: string,
    name: string,
    prefix: string,
    repository,
    target: gitObject,
  }
  and publicKeyConnection = {
    edges: option(array(option(publicKeyEdge))),
    nodes: option(array(option(publicKey))),
    pageInfo,
    totalCount: int,
  }
  and gist = {
    comments: gistCommentConnection,
    createdAt: dateTime,
    description: option(string),
    id: string,
    isPublic: bool,
    name: string,
    owner: option(repositoryOwner),
    pushedAt: option(dateTime),
    stargazers: stargazerConnection,
    updatedAt: dateTime,
    viewerHasStarred: bool,
  }
  and declineTopicSuggestionPayload = {
    clientMutationId: option(string),
    topic,
  }
  and pullRequestConnection = {
    edges: option(array(option(pullRequestEdge))),
    nodes: option(array(option(pullRequest))),
    pageInfo,
    totalCount: int,
  }
  and followingConnection = {
    edges: option(array(option(userEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and topicConnection = {
    edges: option(array(option(topicEdge))),
    nodes: option(array(option(topic))),
    pageInfo,
    totalCount: int,
  }
  and codeOfConduct = {
    body: option(string),
    key: string,
    name: string,
    url: option(uRI),
  }
  and updateProjectCardPayload = {
    clientMutationId: option(string),
    projectCard,
  }
  and branchProtectionRuleConflictConnection = {
    edges: option(array(option(branchProtectionRuleConflictEdge))),
    nodes: option(array(option(branchProtectionRuleConflict))),
    pageInfo,
    totalCount: int,
  }
  and pushAllowanceConnection = {
    edges: option(array(option(pushAllowanceEdge))),
    nodes: option(array(option(pushAllowance))),
    pageInfo,
    totalCount: int,
  }
  and unsubscribedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    subscribable,
  }
  and reactingUserEdge = {
    cursor: string,
    node: user,
    reactedAt: dateTime,
  }
  and milestoneConnection = {
    edges: option(array(option(milestoneEdge))),
    nodes: option(array(option(milestone))),
    pageInfo,
    totalCount: int,
  }
  and reviewRequestRemovedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    pullRequest,
    requestedReviewer: option(requestedReviewer),
  }
  and issueEdge = {
    cursor: string,
    node: option(issue),
  }
  and removedFromProjectEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and mutation = {
    acceptTopicSuggestion: option(acceptTopicSuggestionPayload),
    addComment: option(addCommentPayload),
    addProjectCard: option(addProjectCardPayload),
    addProjectColumn: option(addProjectColumnPayload),
    addPullRequestReview: option(addPullRequestReviewPayload),
    addPullRequestReviewComment: option(addPullRequestReviewCommentPayload),
    addReaction: option(addReactionPayload),
    addStar: option(addStarPayload),
    createBranchProtectionRule: option(createBranchProtectionRulePayload),
    createProject: option(createProjectPayload),
    declineTopicSuggestion: option(declineTopicSuggestionPayload),
    deleteBranchProtectionRule: option(deleteBranchProtectionRulePayload),
    deleteProject: option(deleteProjectPayload),
    deleteProjectCard: option(deleteProjectCardPayload),
    deleteProjectColumn: option(deleteProjectColumnPayload),
    deletePullRequestReview: option(deletePullRequestReviewPayload),
    dismissPullRequestReview: option(dismissPullRequestReviewPayload),
    lockLockable: option(lockLockablePayload),
    moveProjectCard: option(moveProjectCardPayload),
    moveProjectColumn: option(moveProjectColumnPayload),
    removeOutsideCollaborator: option(removeOutsideCollaboratorPayload),
    removeReaction: option(removeReactionPayload),
    removeStar: option(removeStarPayload),
    requestReviews: option(requestReviewsPayload),
    submitPullRequestReview: option(submitPullRequestReviewPayload),
    unlockLockable: option(unlockLockablePayload),
    updateBranchProtectionRule: option(updateBranchProtectionRulePayload),
    updateProject: option(updateProjectPayload),
    updateProjectCard: option(updateProjectCardPayload),
    updateProjectColumn: option(updateProjectColumnPayload),
    updatePullRequestReview: option(updatePullRequestReviewPayload),
    updatePullRequestReviewComment:
      option(updatePullRequestReviewCommentPayload),
    updateSubscription: option(updateSubscriptionPayload),
    updateTopics: option(updateTopicsPayload),
  }
  and license = {
    body: string,
    conditions: array(option(licenseRule)),
    description: option(string),
    featured: bool,
    hidden: bool,
    id: string,
    implementation: option(string),
    key: string,
    limitations: array(option(licenseRule)),
    name: string,
    nickname: option(string),
    permissions: array(option(licenseRule)),
    pseudoLicense: bool,
    spdxId: option(string),
    url: option(uRI),
  }
  and headRefDeletedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    headRef: option(ref),
    headRefName: string,
    id: string,
    pullRequest,
  }
  and branchProtectionRuleConflictEdge = {
    cursor: string,
    node: option(branchProtectionRuleConflict),
  }
  and addReactionPayload = {
    clientMutationId: option(string),
    reaction,
    subject: reactable,
  }
  and branchProtectionRuleConflict = {
    branchProtectionRule: option(branchProtectionRule),
    conflictingBranchProtectionRule: option(branchProtectionRule),
    ref: option(ref),
  }
  and pullRequestReviewThread = {
    comments: pullRequestReviewCommentConnection,
    id: string,
    pullRequest,
    repository,
  }
  and repository = {
    assignableUsers: userConnection,
    branchProtectionRules: branchProtectionRuleConnection,
    codeOfConduct: option(codeOfConduct),
    collaborators: option(repositoryCollaboratorConnection),
    commitComments: commitCommentConnection,
    createdAt: dateTime,
    databaseId: option(int),
    defaultBranchRef: option(ref),
    deployKeys: deployKeyConnection,
    deployments: deploymentConnection,
    description: option(string),
    descriptionHTML: hTML,
    diskUsage: option(int),
    forkCount: int,
    forks: repositoryConnection,
    hasIssuesEnabled: bool,
    hasWikiEnabled: bool,
    homepageUrl: option(uRI),
    id: string,
    isArchived: bool,
    isFork: bool,
    isLocked: bool,
    isMirror: bool,
    isPrivate: bool,
    issue: option(issue),
    issueOrPullRequest: option(issueOrPullRequest),
    issues: issueConnection,
    label: option(label),
    labels: option(labelConnection),
    languages: option(languageConnection),
    licenseInfo: option(license),
    lockReason: option(repositoryLockReason),
    mentionableUsers: userConnection,
    mergeCommitAllowed: bool,
    milestone: option(milestone),
    milestones: option(milestoneConnection),
    mirrorUrl: option(uRI),
    name: string,
    nameWithOwner: string,
    object_: option(gitObject),
    owner: repositoryOwner,
    parent: option(repository),
    primaryLanguage: option(language),
    project: option(project),
    projects: projectConnection,
    projectsResourcePath: uRI,
    projectsUrl: uRI,
    protectedBranches: protectedBranchConnection,
    pullRequest: option(pullRequest),
    pullRequests: pullRequestConnection,
    pushedAt: option(dateTime),
    rebaseMergeAllowed: bool,
    ref: option(ref),
    refs: option(refConnection),
    release: option(release),
    releases: releaseConnection,
    repositoryTopics: repositoryTopicConnection,
    resourcePath: uRI,
    shortDescriptionHTML: hTML,
    squashMergeAllowed: bool,
    sshUrl: gitSSHRemote,
    stargazers: stargazerConnection,
    updatedAt: dateTime,
    url: uRI,
    viewerCanAdminister: bool,
    viewerCanCreateProjects: bool,
    viewerCanSubscribe: bool,
    viewerCanUpdateTopics: bool,
    viewerHasStarred: bool,
    viewerPermission: option(repositoryPermission),
    viewerSubscription: option(subscriptionState),
    watchers: userConnection,
  }
  and updateProjectPayload = {
    clientMutationId: option(string),
    project,
  }
  and repositoryTopicEdge = {
    cursor: string,
    node: option(repositoryTopic),
  }
  and milestoneEdge = {
    cursor: string,
    node: option(milestone),
  }
  and labelConnection = {
    edges: option(array(option(labelEdge))),
    nodes: option(array(option(label))),
    pageInfo,
    totalCount: int,
  }
  and projectColumn = {
    cards: projectCardConnection,
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
    name: string,
    project,
    purpose: option(projectColumnPurpose),
    resourcePath: uRI,
    updatedAt: dateTime,
    url: uRI,
  }
  and repositoryInvitation = {
    id: string,
    invitee: user,
    inviter: user,
    permission: repositoryPermission,
    repository: option(repositoryInfo),
  }
  and deleteProjectCardPayload = {
    clientMutationId: option(string),
    column: projectColumn,
    deletedCardId: string,
  }
  and release = {
    author: option(user),
    createdAt: dateTime,
    description: option(string),
    id: string,
    isDraft: bool,
    isPrerelease: bool,
    name: option(string),
    publishedAt: option(dateTime),
    releaseAssets: releaseAssetConnection,
    resourcePath: uRI,
    tag: option(ref),
    updatedAt: dateTime,
    url: uRI,
  }
  and stargazerEdge = {
    cursor: string,
    node: user,
    starredAt: dateTime,
  }
  and deployedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    deployment,
    id: string,
    pullRequest,
    ref: option(ref),
  }
  and pullRequestReviewEdge = {
    cursor: string,
    node: option(pullRequestReview),
  }
  and projectCardConnection = {
    edges: option(array(option(projectCardEdge))),
    nodes: option(array(option(projectCard))),
    pageInfo,
    totalCount: int,
  }
  and updateTopicsPayload = {
    clientMutationId: option(string),
    invalidTopicNames: option(array(string)),
    repository,
  }
  and deleteBranchProtectionRulePayload = {clientMutationId: option(string)}
  and unlockLockablePayload = {
    clientMutationId: option(string),
    unlockedRecord: option(lockable),
  }
  and reviewDismissalAllowanceEdge = {
    cursor: string,
    node: option(reviewDismissalAllowance),
  }
  and lockedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    lockReason: option(lockReason),
    lockable,
  }
  and pushAllowanceEdge = {
    cursor: string,
    node: option(pushAllowance),
  }
  and moveProjectColumnPayload = {
    clientMutationId: option(string),
    columnEdge: projectColumnEdge,
  }
  and branchProtectionRuleEdge = {
    cursor: string,
    node: option(branchProtectionRule),
  }
  and acceptTopicSuggestionPayload = {
    clientMutationId: option(string),
    topic,
  }
  and marketplaceListingEdge = {
    cursor: string,
    node: option(marketplaceListing),
  }
  and teamMemberConnection = {
    edges: option(array(option(teamMemberEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and movedColumnsInProjectEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and createBranchProtectionRulePayload = {
    branchProtectionRule: option(branchProtectionRule),
    clientMutationId: option(string),
  }
  and blob = {
    abbreviatedOid: string,
    byteSize: int,
    commitResourcePath: uRI,
    commitUrl: uRI,
    id: string,
    isBinary: bool,
    isTruncated: bool,
    oid: gitObjectID,
    repository,
    text: option(string),
  }
  and organization = {
    avatarUrl: uRI,
    databaseId: option(int),
    description: option(string),
    email: option(string),
    id: string,
    isVerified: bool,
    location: option(string),
    login: string,
    members: userConnection,
    name: option(string),
    newTeamResourcePath: uRI,
    newTeamUrl: uRI,
    organizationBillingEmail: option(string),
    pinnedRepositories: repositoryConnection,
    project: option(project),
    projects: projectConnection,
    projectsResourcePath: uRI,
    projectsUrl: uRI,
    repositories: repositoryConnection,
    repository: option(repository),
    requiresTwoFactorAuthentication: option(bool),
    resourcePath: uRI,
    samlIdentityProvider: option(organizationIdentityProvider),
    team: option(team),
    teams: teamConnection,
    teamsResourcePath: uRI,
    teamsUrl: uRI,
    url: uRI,
    viewerCanAdminister: bool,
    viewerCanCreateProjects: bool,
    viewerCanCreateRepositories: bool,
    viewerCanCreateTeams: bool,
    viewerIsAMember: bool,
    websiteUrl: option(uRI),
  }
  and pullRequestReviewComment = {
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    commit,
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    diffHunk: string,
    draftedAt: dateTime,
    editor: option(actor),
    id: string,
    includesCreatedEdit: bool,
    lastEditedAt: option(dateTime),
    originalCommit: option(commit),
    originalPosition: int,
    outdated: bool,
    path: string,
    position: option(int),
    publishedAt: option(dateTime),
    pullRequest,
    pullRequestReview: option(pullRequestReview),
    reactionGroups: option(array(reactionGroup)),
    reactions: reactionConnection,
    replyTo: option(pullRequestReviewComment),
    repository,
    resourcePath: uRI,
    state: pullRequestReviewCommentState,
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanDelete: bool,
    viewerCanReact: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
  }
  and organizationInvitation = {
    createdAt: dateTime,
    email: option(string),
    id: string,
    invitationType: organizationInvitationType,
    invitee: option(user),
    inviter: user,
    organization,
    role: organizationInvitationRole,
  }
  and dismissPullRequestReviewPayload = {
    clientMutationId: option(string),
    pullRequestReview,
  }
  and deploymentStatus = {
    createdAt: dateTime,
    creator: option(actor),
    deployment,
    description: option(string),
    environmentUrl: option(uRI),
    id: string,
    logUrl: option(uRI),
    state: deploymentStatusState,
    updatedAt: dateTime,
  }
  and submitPullRequestReviewPayload = {
    clientMutationId: option(string),
    pullRequestReview,
  }
  and appEdge = {
    cursor: string,
    node: option(app),
  }
  and updatePullRequestReviewPayload = {
    clientMutationId: option(string),
    pullRequestReview,
  }
  and externalIdentity = {
    guid: string,
    id: string,
    organizationInvitation: option(organizationInvitation),
    samlIdentity: option(externalIdentitySamlAttributes),
    scimIdentity: option(externalIdentityScimAttributes),
    user: option(user),
  }
  and unlockedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    lockable,
  }
  and team = {
    ancestors: teamConnection,
    avatarUrl: option(uRI),
    childTeams: teamConnection,
    combinedSlug: string,
    createdAt: dateTime,
    description: option(string),
    editTeamResourcePath: uRI,
    editTeamUrl: uRI,
    id: string,
    invitations: option(organizationInvitationConnection),
    members: teamMemberConnection,
    membersResourcePath: uRI,
    membersUrl: uRI,
    name: string,
    newTeamResourcePath: uRI,
    newTeamUrl: uRI,
    organization,
    parentTeam: option(team),
    privacy: teamPrivacy,
    repositories: teamRepositoryConnection,
    repositoriesResourcePath: uRI,
    repositoriesUrl: uRI,
    resourcePath: uRI,
    slug: string,
    teamsResourcePath: uRI,
    teamsUrl: uRI,
    updatedAt: dateTime,
    url: uRI,
    viewerCanAdminister: bool,
    viewerCanSubscribe: bool,
    viewerSubscription: option(subscriptionState),
  }
  and pullRequest = {
    activeLockReason: option(lockReason),
    additions: int,
    assignees: userConnection,
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    baseRef: option(ref),
    baseRefName: string,
    baseRefOid: gitObjectID,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    changedFiles: int,
    closed: bool,
    closedAt: option(dateTime),
    comments: issueCommentConnection,
    commits: pullRequestCommitConnection,
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    deletions: int,
    editor: option(actor),
    headRef: option(ref),
    headRefName: string,
    headRefOid: gitObjectID,
    headRepository: option(repository),
    headRepositoryOwner: option(repositoryOwner),
    id: string,
    includesCreatedEdit: bool,
    isCrossRepository: bool,
    labels: option(labelConnection),
    lastEditedAt: option(dateTime),
    locked: bool,
    maintainerCanModify: bool,
    mergeCommit: option(commit),
    mergeable: mergeableState,
    merged: bool,
    mergedAt: option(dateTime),
    mergedBy: option(actor),
    milestone: option(milestone),
    number: int,
    participants: userConnection,
    permalink: uRI,
    potentialMergeCommit: option(commit),
    projectCards: projectCardConnection,
    publishedAt: option(dateTime),
    reactionGroups: option(array(reactionGroup)),
    reactions: reactionConnection,
    repository,
    resourcePath: uRI,
    revertResourcePath: uRI,
    revertUrl: uRI,
    reviewRequests: option(reviewRequestConnection),
    reviews: option(pullRequestReviewConnection),
    state: pullRequestState,
    suggestedReviewers: array(option(suggestedReviewer)),
    timeline: pullRequestTimelineConnection,
    title: string,
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanApplySuggestion: bool,
    viewerCanReact: bool,
    viewerCanSubscribe: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
    viewerSubscription: option(subscriptionState),
  }
  and closedEvent = {
    actor: option(actor),
    closable,
    closer: option(closer),
    createdAt: dateTime,
    id: string,
    resourcePath: uRI,
    url: uRI,
  }
  and removeOutsideCollaboratorPayload = {
    clientMutationId: option(string),
    removedUser: user,
  }
  and rateLimit = {
    cost: int,
    limit: int,
    nodeCount: int,
    remaining: int,
    resetAt: dateTime,
  }
  and protectedBranchEdge = {
    cursor: string,
    node: option(protectedBranch),
  }
  and commitComment = {
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    commit: option(commit),
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    editor: option(actor),
    id: string,
    includesCreatedEdit: bool,
    lastEditedAt: option(dateTime),
    path: option(string),
    position: option(int),
    publishedAt: option(dateTime),
    reactionGroups: option(array(reactionGroup)),
    reactions: reactionConnection,
    repository,
    resourcePath: uRI,
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanDelete: bool,
    viewerCanReact: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
  }
  and deploymentEnvironmentChangedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    deploymentStatus,
    id: string,
    pullRequest,
  }
  and deployKeyEdge = {
    cursor: string,
    node: option(deployKey),
  }
  and protectedBranch = {
    creator: option(actor),
    hasDismissableStaleReviews: bool,
    hasRequiredReviews: bool,
    hasRequiredStatusChecks: bool,
    hasRestrictedPushes: bool,
    hasRestrictedReviewDismissals: bool,
    hasStrictRequiredStatusChecks: bool,
    id: string,
    isAdminEnforced: bool,
    name: string,
    pushAllowances: pushAllowanceConnection,
    repository,
    requiredStatusCheckContexts: option(array(option(string))),
    reviewDismissalAllowances: reviewDismissalAllowanceConnection,
  }
  and mergedEvent = {
    actor: option(actor),
    commit: option(commit),
    createdAt: dateTime,
    id: string,
    mergeRef: option(ref),
    mergeRefName: string,
    pullRequest,
    resourcePath: uRI,
    url: uRI,
  }
  and reactionGroup = {
    content: reactionContent,
    createdAt: option(dateTime),
    subject: reactable,
    users: reactingUserConnection,
    viewerHasReacted: bool,
  }
  and userContentEditConnection = {
    edges: option(array(option(userContentEditEdge))),
    nodes: option(array(option(userContentEdit))),
    pageInfo,
    totalCount: int,
  }
  and project = {
    body: option(string),
    bodyHTML: hTML,
    closed: bool,
    closedAt: option(dateTime),
    columns: projectColumnConnection,
    createdAt: dateTime,
    creator: option(actor),
    databaseId: option(int),
    id: string,
    name: string,
    number: int,
    owner: projectOwner,
    pendingCards: projectCardConnection,
    resourcePath: uRI,
    state: projectState,
    updatedAt: dateTime,
    url: uRI,
    viewerCanUpdate: bool,
  }
  and followerConnection = {
    edges: option(array(option(userEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and commit = {
    abbreviatedOid: string,
    additions: int,
    author: option(gitActor),
    authoredByCommitter: bool,
    authoredDate: dateTime,
    blame,
    changedFiles: int,
    comments: commitCommentConnection,
    commitResourcePath: uRI,
    commitUrl: uRI,
    committedDate: dateTime,
    committedViaWeb: bool,
    committer: option(gitActor),
    deletions: int,
    history: commitHistoryConnection,
    id: string,
    message: string,
    messageBody: string,
    messageBodyHTML: hTML,
    messageHeadline: string,
    messageHeadlineHTML: hTML,
    oid: gitObjectID,
    parents: commitConnection,
    pushedDate: option(dateTime),
    repository,
    resourcePath: uRI,
    signature: option(gitSignature),
    status: option(status),
    tarballUrl: uRI,
    tree,
    treeResourcePath: uRI,
    treeUrl: uRI,
    url: uRI,
    viewerCanSubscribe: bool,
    viewerSubscription: option(subscriptionState),
    zipballUrl: uRI,
  }
  and marketplaceListingConnection = {
    edges: option(array(option(marketplaceListingEdge))),
    nodes: option(array(option(marketplaceListing))),
    pageInfo,
    totalCount: int,
  }
  and repositoryTopic = {
    id: string,
    resourcePath: uRI,
    topic,
    url: uRI,
  }
  and issueTimelineConnection = {
    edges: option(array(option(issueTimelineItemEdge))),
    nodes: option(array(option(issueTimelineItem))),
    pageInfo,
    totalCount: int,
  }
  and reactionConnection = {
    edges: option(array(option(reactionEdge))),
    nodes: option(array(option(reaction))),
    pageInfo,
    totalCount: int,
    viewerHasReacted: bool,
  }
  and issue = {
    activeLockReason: option(lockReason),
    assignees: userConnection,
    author: option(actor),
    authorAssociation: commentAuthorAssociation,
    body: string,
    bodyHTML: hTML,
    bodyText: string,
    closed: bool,
    closedAt: option(dateTime),
    comments: issueCommentConnection,
    createdAt: dateTime,
    createdViaEmail: bool,
    databaseId: option(int),
    editor: option(actor),
    id: string,
    includesCreatedEdit: bool,
    labels: option(labelConnection),
    lastEditedAt: option(dateTime),
    locked: bool,
    milestone: option(milestone),
    number: int,
    participants: userConnection,
    projectCards: projectCardConnection,
    publishedAt: option(dateTime),
    reactionGroups: option(array(reactionGroup)),
    reactions: reactionConnection,
    repository,
    resourcePath: uRI,
    state: issueState,
    timeline: issueTimelineConnection,
    title: string,
    updatedAt: dateTime,
    url: uRI,
    userContentEdits: option(userContentEditConnection),
    viewerCanReact: bool,
    viewerCanSubscribe: bool,
    viewerCanUpdate: bool,
    viewerCannotUpdateReasons: array(commentCannotUpdateReason),
    viewerDidAuthor: bool,
    viewerSubscription: option(subscriptionState),
  }
  and releaseAssetEdge = {
    cursor: string,
    node: option(releaseAsset),
  }
  and addedToProjectEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and reviewRequestedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    pullRequest,
    requestedReviewer: option(requestedReviewer),
  }
  and organizationEdge = {
    cursor: string,
    node: option(organization),
  }
  and projectCardEdge = {
    cursor: string,
    node: option(projectCard),
  }
  and repositoryConnection = {
    edges: option(array(option(repositoryEdge))),
    nodes: option(array(option(repository))),
    pageInfo,
    totalCount: int,
    totalDiskUsage: int,
  }
  and releaseEdge = {
    cursor: string,
    node: option(release),
  }
  and licenseRule = {
    description: string,
    key: string,
    label: string,
  }
  and userEdge = {
    cursor: string,
    node: option(user),
  }
  and gistCommentConnection = {
    edges: option(array(option(gistCommentEdge))),
    nodes: option(array(option(gistComment))),
    pageInfo,
    totalCount: int,
  }
  and query = {
    codeOfConduct: option(codeOfConduct),
    codesOfConduct: option(array(option(codeOfConduct))),
    license: option(license),
    licenses: array(option(license)),
    marketplaceCategories: array(marketplaceCategory),
    marketplaceCategory: option(marketplaceCategory),
    marketplaceListing: option(marketplaceListing),
    marketplaceListings: marketplaceListingConnection,
    meta: gitHubMetadata,
    node: option(node),
    nodes: array(option(node)),
    organization: option(organization),
    rateLimit: option(rateLimit),
    relay: query,
    repository: option(repository),
    repositoryOwner: option(repositoryOwner),
    resource: option(uniformResourceLocatable),
    search: searchResultItemConnection,
    topic: option(topic),
    user: option(user),
    viewer: user,
  }
  and deploymentStatusConnection = {
    edges: option(array(option(deploymentStatusEdge))),
    nodes: option(array(option(deploymentStatus))),
    pageInfo,
    totalCount: int,
  }
  and starredRepositoryEdge = {
    cursor: string,
    node: repository,
    starredAt: dateTime,
  }
  and unlabeledEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    label,
    labelable,
  }
  and reviewRequestEdge = {
    cursor: string,
    node: option(reviewRequest),
  }
  and label = {
    color: string,
    createdAt: option(dateTime),
    description: option(string),
    id: string,
    isDefault: bool,
    issues: issueConnection,
    name: string,
    pullRequests: pullRequestConnection,
    repository,
    resourcePath: uRI,
    updatedAt: option(dateTime),
    url: uRI,
  }
  and organizationInvitationConnection = {
    edges: option(array(option(organizationInvitationEdge))),
    nodes: option(array(option(organizationInvitation))),
    pageInfo,
    totalCount: int,
  }
  and topic = {
    id: string,
    name: string,
    relatedTopics: array(topic),
    stargazers: stargazerConnection,
    viewerHasStarred: bool,
  }
  and issueTimelineItemsEdge = {
    cursor: string,
    node: option(issueTimelineItems),
  }
  and teamConnection = {
    edges: option(array(option(teamEdge))),
    nodes: option(array(option(team))),
    pageInfo,
    totalCount: int,
  }
  and commentDeletedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and updateSubscriptionPayload = {
    clientMutationId: option(string),
    subscribable,
  }
  and starredRepositoryConnection = {
    edges: option(array(option(starredRepositoryEdge))),
    nodes: option(array(option(repository))),
    pageInfo,
    totalCount: int,
  }
  and gitHubMetadata = {
    gitHubServicesSha: gitObjectID,
    gitIpAddresses: option(array(string)),
    hookIpAddresses: option(array(string)),
    importerIpAddresses: option(array(string)),
    isPasswordAuthenticationVerifiable: bool,
    pagesIpAddresses: option(array(string)),
  }
  and addCommentPayload = {
    clientMutationId: option(string),
    commentEdge: issueCommentEdge,
    subject: node,
    timelineEdge: issueTimelineItemEdge,
  }
  and textMatch = {
    fragment: string,
    highlights: array(textMatchHighlight),
    property: string,
  }
  and pullRequestTimelineItemsEdge = {
    cursor: string,
    node: option(pullRequestTimelineItems),
  }
  and moveProjectCardPayload = {
    cardEdge: projectCardEdge,
    clientMutationId: option(string),
  }
  and gistConnection = {
    edges: option(array(option(gistEdge))),
    nodes: option(array(option(gist))),
    pageInfo,
    totalCount: int,
  }
  and deploymentConnection = {
    edges: option(array(option(deploymentEdge))),
    nodes: option(array(option(deployment))),
    pageInfo,
    totalCount: int,
  }
  and repositoryCollaboratorConnection = {
    edges: option(array(option(repositoryCollaboratorEdge))),
    nodes: option(array(option(user))),
    pageInfo,
    totalCount: int,
  }
  and externalIdentityScimAttributes = {username: option(string)}
  and lockLockablePayload = {
    clientMutationId: option(string),
    lockedRecord: option(lockable),
  }
  and updatePullRequestReviewCommentPayload = {
    clientMutationId: option(string),
    pullRequestReviewComment,
  }
  and smimeSignature = {
    email: string,
    isValid: bool,
    payload: string,
    signature: string,
    signer: option(user),
    state: gitSignatureState,
    wasSignedByGitHub: bool,
  }
  and repositoryTopicConnection = {
    edges: option(array(option(repositoryTopicEdge))),
    nodes: option(array(option(repositoryTopic))),
    pageInfo,
    totalCount: int,
  }
  and milestone = {
    closed: bool,
    closedAt: option(dateTime),
    createdAt: dateTime,
    creator: option(actor),
    description: option(string),
    dueOn: option(dateTime),
    id: string,
    issues: issueConnection,
    number: int,
    pullRequests: pullRequestConnection,
    repository,
    resourcePath: uRI,
    state: milestoneState,
    title: string,
    updatedAt: dateTime,
    url: uRI,
  }
  and deployKey = {
    createdAt: dateTime,
    id: string,
    key: string,
    readOnly: bool,
    title: string,
    verified: bool,
  }
  and externalIdentitySamlAttributes = {nameId: option(string)}
  and subscribedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    id: string,
    subscribable,
  }
  and pullRequestCommitConnection = {
    edges: option(array(option(pullRequestCommitEdge))),
    nodes: option(array(option(pullRequestCommit))),
    pageInfo,
    totalCount: int,
  }
  and gistCommentEdge = {
    cursor: string,
    node: option(gistComment),
  }
  and issueConnection = {
    edges: option(array(option(issueEdge))),
    nodes: option(array(option(issue))),
    pageInfo,
    totalCount: int,
  }
  and unknownSignature = {
    email: string,
    isValid: bool,
    payload: string,
    signature: string,
    signer: option(user),
    state: gitSignatureState,
    wasSignedByGitHub: bool,
  }
  and pullRequestReviewCommentEdge = {
    cursor: string,
    node: option(pullRequestReviewComment),
  }
  and reviewDismissedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
    message: string,
    messageHtml: hTML,
    previousReviewState: pullRequestReviewState,
    pullRequest,
    pullRequestCommit: option(pullRequestCommit),
    resourcePath: uRI,
    review: option(pullRequestReview),
    url: uRI,
  }
  and reopenedEvent = {
    actor: option(actor),
    closable,
    createdAt: dateTime,
    id: string,
  }
  and mentionedEvent = {
    actor: option(actor),
    createdAt: dateTime,
    databaseId: option(int),
    id: string,
  }
  and referencedEvent = {
    actor: option(actor),
    commit: option(commit),
    commitRepository: repository,
    createdAt: dateTime,
    id: string,
    isCrossRepository: bool,
    isDirectReference: bool,
    subject: referencedSubject,
  };
  external issueToMilestoneItem: issue => milestoneItem = "%identity";
  external pullRequestToMilestoneItem: pullRequest => milestoneItem =
    "%identity";
  external teamToReviewDismissalAllowanceActor:
    team => reviewDismissalAllowanceActor =
    "%identity";
  external userToReviewDismissalAllowanceActor:
    user => reviewDismissalAllowanceActor =
    "%identity";
  external teamToRequestedReviewer: team => requestedReviewer = "%identity";
  external userToRequestedReviewer: user => requestedReviewer = "%identity";
  external issueToProjectCardItem: issue => projectCardItem = "%identity";
  external pullRequestToProjectCardItem: pullRequest => projectCardItem =
    "%identity";
  external issueToReferencedSubject: issue => referencedSubject = "%identity";
  external pullRequestToReferencedSubject: pullRequest => referencedSubject =
    "%identity";
  external addedToProjectEventToIssueTimelineItems:
    addedToProjectEvent => issueTimelineItems =
    "%identity";
  external assignedEventToIssueTimelineItems:
    assignedEvent => issueTimelineItems =
    "%identity";
  external closedEventToIssueTimelineItems: closedEvent => issueTimelineItems =
    "%identity";
  external commentDeletedEventToIssueTimelineItems:
    commentDeletedEvent => issueTimelineItems =
    "%identity";
  external convertedNoteToIssueEventToIssueTimelineItems:
    convertedNoteToIssueEvent => issueTimelineItems =
    "%identity";
  external crossReferencedEventToIssueTimelineItems:
    crossReferencedEvent => issueTimelineItems =
    "%identity";
  external demilestonedEventToIssueTimelineItems:
    demilestonedEvent => issueTimelineItems =
    "%identity";
  external issueCommentToIssueTimelineItems: issueComment => issueTimelineItems =
    "%identity";
  external labeledEventToIssueTimelineItems: labeledEvent => issueTimelineItems =
    "%identity";
  external lockedEventToIssueTimelineItems: lockedEvent => issueTimelineItems =
    "%identity";
  external mentionedEventToIssueTimelineItems:
    mentionedEvent => issueTimelineItems =
    "%identity";
  external milestonedEventToIssueTimelineItems:
    milestonedEvent => issueTimelineItems =
    "%identity";
  external movedColumnsInProjectEventToIssueTimelineItems:
    movedColumnsInProjectEvent => issueTimelineItems =
    "%identity";
  external referencedEventToIssueTimelineItems:
    referencedEvent => issueTimelineItems =
    "%identity";
  external removedFromProjectEventToIssueTimelineItems:
    removedFromProjectEvent => issueTimelineItems =
    "%identity";
  external renamedTitleEventToIssueTimelineItems:
    renamedTitleEvent => issueTimelineItems =
    "%identity";
  external reopenedEventToIssueTimelineItems:
    reopenedEvent => issueTimelineItems =
    "%identity";
  external subscribedEventToIssueTimelineItems:
    subscribedEvent => issueTimelineItems =
    "%identity";
  external unassignedEventToIssueTimelineItems:
    unassignedEvent => issueTimelineItems =
    "%identity";
  external unlabeledEventToIssueTimelineItems:
    unlabeledEvent => issueTimelineItems =
    "%identity";
  external unlockedEventToIssueTimelineItems:
    unlockedEvent => issueTimelineItems =
    "%identity";
  external unsubscribedEventToIssueTimelineItems:
    unsubscribedEvent => issueTimelineItems =
    "%identity";
  external assignedEventToPullRequestTimelineItem:
    assignedEvent => pullRequestTimelineItem =
    "%identity";
  external baseRefForcePushedEventToPullRequestTimelineItem:
    baseRefForcePushedEvent => pullRequestTimelineItem =
    "%identity";
  external closedEventToPullRequestTimelineItem:
    closedEvent => pullRequestTimelineItem =
    "%identity";
  external commitToPullRequestTimelineItem: commit => pullRequestTimelineItem =
    "%identity";
  external commitCommentThreadToPullRequestTimelineItem:
    commitCommentThread => pullRequestTimelineItem =
    "%identity";
  external crossReferencedEventToPullRequestTimelineItem:
    crossReferencedEvent => pullRequestTimelineItem =
    "%identity";
  external demilestonedEventToPullRequestTimelineItem:
    demilestonedEvent => pullRequestTimelineItem =
    "%identity";
  external deployedEventToPullRequestTimelineItem:
    deployedEvent => pullRequestTimelineItem =
    "%identity";
  external deploymentEnvironmentChangedEventToPullRequestTimelineItem:
    deploymentEnvironmentChangedEvent => pullRequestTimelineItem =
    "%identity";
  external headRefDeletedEventToPullRequestTimelineItem:
    headRefDeletedEvent => pullRequestTimelineItem =
    "%identity";
  external headRefForcePushedEventToPullRequestTimelineItem:
    headRefForcePushedEvent => pullRequestTimelineItem =
    "%identity";
  external headRefRestoredEventToPullRequestTimelineItem:
    headRefRestoredEvent => pullRequestTimelineItem =
    "%identity";
  external issueCommentToPullRequestTimelineItem:
    issueComment => pullRequestTimelineItem =
    "%identity";
  external labeledEventToPullRequestTimelineItem:
    labeledEvent => pullRequestTimelineItem =
    "%identity";
  external lockedEventToPullRequestTimelineItem:
    lockedEvent => pullRequestTimelineItem =
    "%identity";
  external mergedEventToPullRequestTimelineItem:
    mergedEvent => pullRequestTimelineItem =
    "%identity";
  external milestonedEventToPullRequestTimelineItem:
    milestonedEvent => pullRequestTimelineItem =
    "%identity";
  external pullRequestReviewToPullRequestTimelineItem:
    pullRequestReview => pullRequestTimelineItem =
    "%identity";
  external pullRequestReviewCommentToPullRequestTimelineItem:
    pullRequestReviewComment => pullRequestTimelineItem =
    "%identity";
  external pullRequestReviewThreadToPullRequestTimelineItem:
    pullRequestReviewThread => pullRequestTimelineItem =
    "%identity";
  external referencedEventToPullRequestTimelineItem:
    referencedEvent => pullRequestTimelineItem =
    "%identity";
  external renamedTitleEventToPullRequestTimelineItem:
    renamedTitleEvent => pullRequestTimelineItem =
    "%identity";
  external reopenedEventToPullRequestTimelineItem:
    reopenedEvent => pullRequestTimelineItem =
    "%identity";
  external reviewDismissedEventToPullRequestTimelineItem:
    reviewDismissedEvent => pullRequestTimelineItem =
    "%identity";
  external reviewRequestRemovedEventToPullRequestTimelineItem:
    reviewRequestRemovedEvent => pullRequestTimelineItem =
    "%identity";
  external reviewRequestedEventToPullRequestTimelineItem:
    reviewRequestedEvent => pullRequestTimelineItem =
    "%identity";
  external subscribedEventToPullRequestTimelineItem:
    subscribedEvent => pullRequestTimelineItem =
    "%identity";
  external unassignedEventToPullRequestTimelineItem:
    unassignedEvent => pullRequestTimelineItem =
    "%identity";
  external unlabeledEventToPullRequestTimelineItem:
    unlabeledEvent => pullRequestTimelineItem =
    "%identity";
  external unlockedEventToPullRequestTimelineItem:
    unlockedEvent => pullRequestTimelineItem =
    "%identity";
  external unsubscribedEventToPullRequestTimelineItem:
    unsubscribedEvent => pullRequestTimelineItem =
    "%identity";
  external assignedEventToIssueTimelineItem: assignedEvent => issueTimelineItem =
    "%identity";
  external closedEventToIssueTimelineItem: closedEvent => issueTimelineItem =
    "%identity";
  external commitToIssueTimelineItem: commit => issueTimelineItem =
    "%identity";
  external crossReferencedEventToIssueTimelineItem:
    crossReferencedEvent => issueTimelineItem =
    "%identity";
  external demilestonedEventToIssueTimelineItem:
    demilestonedEvent => issueTimelineItem =
    "%identity";
  external issueCommentToIssueTimelineItem: issueComment => issueTimelineItem =
    "%identity";
  external labeledEventToIssueTimelineItem: labeledEvent => issueTimelineItem =
    "%identity";
  external lockedEventToIssueTimelineItem: lockedEvent => issueTimelineItem =
    "%identity";
  external milestonedEventToIssueTimelineItem:
    milestonedEvent => issueTimelineItem =
    "%identity";
  external referencedEventToIssueTimelineItem:
    referencedEvent => issueTimelineItem =
    "%identity";
  external renamedTitleEventToIssueTimelineItem:
    renamedTitleEvent => issueTimelineItem =
    "%identity";
  external reopenedEventToIssueTimelineItem: reopenedEvent => issueTimelineItem =
    "%identity";
  external subscribedEventToIssueTimelineItem:
    subscribedEvent => issueTimelineItem =
    "%identity";
  external unassignedEventToIssueTimelineItem:
    unassignedEvent => issueTimelineItem =
    "%identity";
  external unlabeledEventToIssueTimelineItem:
    unlabeledEvent => issueTimelineItem =
    "%identity";
  external unlockedEventToIssueTimelineItem: unlockedEvent => issueTimelineItem =
    "%identity";
  external unsubscribedEventToIssueTimelineItem:
    unsubscribedEvent => issueTimelineItem =
    "%identity";
  external issueToRenamedTitleSubject: issue => renamedTitleSubject =
    "%identity";
  external pullRequestToRenamedTitleSubject: pullRequest => renamedTitleSubject =
    "%identity";
  external commitToCloser: commit => closer = "%identity";
  external pullRequestToCloser: pullRequest => closer = "%identity";
  external teamToPushAllowanceActor: team => pushAllowanceActor = "%identity";
  external userToPushAllowanceActor: user => pushAllowanceActor = "%identity";
  external issueToIssueOrPullRequest: issue => issueOrPullRequest =
    "%identity";
  external pullRequestToIssueOrPullRequest: pullRequest => issueOrPullRequest =
    "%identity";
  external addedToProjectEventToPullRequestTimelineItems:
    addedToProjectEvent => pullRequestTimelineItems =
    "%identity";
  external assignedEventToPullRequestTimelineItems:
    assignedEvent => pullRequestTimelineItems =
    "%identity";
  external baseRefChangedEventToPullRequestTimelineItems:
    baseRefChangedEvent => pullRequestTimelineItems =
    "%identity";
  external baseRefForcePushedEventToPullRequestTimelineItems:
    baseRefForcePushedEvent => pullRequestTimelineItems =
    "%identity";
  external closedEventToPullRequestTimelineItems:
    closedEvent => pullRequestTimelineItems =
    "%identity";
  external commentDeletedEventToPullRequestTimelineItems:
    commentDeletedEvent => pullRequestTimelineItems =
    "%identity";
  external convertedNoteToIssueEventToPullRequestTimelineItems:
    convertedNoteToIssueEvent => pullRequestTimelineItems =
    "%identity";
  external crossReferencedEventToPullRequestTimelineItems:
    crossReferencedEvent => pullRequestTimelineItems =
    "%identity";
  external demilestonedEventToPullRequestTimelineItems:
    demilestonedEvent => pullRequestTimelineItems =
    "%identity";
  external deployedEventToPullRequestTimelineItems:
    deployedEvent => pullRequestTimelineItems =
    "%identity";
  external deploymentEnvironmentChangedEventToPullRequestTimelineItems:
    deploymentEnvironmentChangedEvent => pullRequestTimelineItems =
    "%identity";
  external headRefDeletedEventToPullRequestTimelineItems:
    headRefDeletedEvent => pullRequestTimelineItems =
    "%identity";
  external headRefForcePushedEventToPullRequestTimelineItems:
    headRefForcePushedEvent => pullRequestTimelineItems =
    "%identity";
  external headRefRestoredEventToPullRequestTimelineItems:
    headRefRestoredEvent => pullRequestTimelineItems =
    "%identity";
  external issueCommentToPullRequestTimelineItems:
    issueComment => pullRequestTimelineItems =
    "%identity";
  external labeledEventToPullRequestTimelineItems:
    labeledEvent => pullRequestTimelineItems =
    "%identity";
  external lockedEventToPullRequestTimelineItems:
    lockedEvent => pullRequestTimelineItems =
    "%identity";
  external mentionedEventToPullRequestTimelineItems:
    mentionedEvent => pullRequestTimelineItems =
    "%identity";
  external mergedEventToPullRequestTimelineItems:
    mergedEvent => pullRequestTimelineItems =
    "%identity";
  external milestonedEventToPullRequestTimelineItems:
    milestonedEvent => pullRequestTimelineItems =
    "%identity";
  external movedColumnsInProjectEventToPullRequestTimelineItems:
    movedColumnsInProjectEvent => pullRequestTimelineItems =
    "%identity";
  external pullRequestCommitToPullRequestTimelineItems:
    pullRequestCommit => pullRequestTimelineItems =
    "%identity";
  external pullRequestReviewToPullRequestTimelineItems:
    pullRequestReview => pullRequestTimelineItems =
    "%identity";
  external pullRequestReviewThreadToPullRequestTimelineItems:
    pullRequestReviewThread => pullRequestTimelineItems =
    "%identity";
  external referencedEventToPullRequestTimelineItems:
    referencedEvent => pullRequestTimelineItems =
    "%identity";
  external removedFromProjectEventToPullRequestTimelineItems:
    removedFromProjectEvent => pullRequestTimelineItems =
    "%identity";
  external renamedTitleEventToPullRequestTimelineItems:
    renamedTitleEvent => pullRequestTimelineItems =
    "%identity";
  external reopenedEventToPullRequestTimelineItems:
    reopenedEvent => pullRequestTimelineItems =
    "%identity";
  external reviewDismissedEventToPullRequestTimelineItems:
    reviewDismissedEvent => pullRequestTimelineItems =
    "%identity";
  external reviewRequestRemovedEventToPullRequestTimelineItems:
    reviewRequestRemovedEvent => pullRequestTimelineItems =
    "%identity";
  external reviewRequestedEventToPullRequestTimelineItems:
    reviewRequestedEvent => pullRequestTimelineItems =
    "%identity";
  external subscribedEventToPullRequestTimelineItems:
    subscribedEvent => pullRequestTimelineItems =
    "%identity";
  external unassignedEventToPullRequestTimelineItems:
    unassignedEvent => pullRequestTimelineItems =
    "%identity";
  external unlabeledEventToPullRequestTimelineItems:
    unlabeledEvent => pullRequestTimelineItems =
    "%identity";
  external unlockedEventToPullRequestTimelineItems:
    unlockedEvent => pullRequestTimelineItems =
    "%identity";
  external unsubscribedEventToPullRequestTimelineItems:
    unsubscribedEvent => pullRequestTimelineItems =
    "%identity";
  external organizationToCollectionItemContent:
    organization => collectionItemContent =
    "%identity";
  external repositoryToCollectionItemContent:
    repository => collectionItemContent =
    "%identity";
  external userToCollectionItemContent: user => collectionItemContent =
    "%identity";
  external issueToSearchResultItem: issue => searchResultItem = "%identity";
  external marketplaceListingToSearchResultItem:
    marketplaceListing => searchResultItem =
    "%identity";
  external organizationToSearchResultItem: organization => searchResultItem =
    "%identity";
  external pullRequestToSearchResultItem: pullRequest => searchResultItem =
    "%identity";
  external repositoryToSearchResultItem: repository => searchResultItem =
    "%identity";
  external userToSearchResultItem: user => searchResultItem = "%identity";
  module Query = {
    type t = {
      codeOfConduct:
        rootResolver(
          {. "key": string},
          codeOfConduct,
          option(codeOfConduct),
        ),
      codesOfConduct:
        rootResolver(
          unit,
          codeOfConduct,
          option(array(option(codeOfConduct))),
        ),
      license: rootResolver({. "key": string}, license, option(license)),
      licenses: rootResolver(unit, license, array(option(license))),
      marketplaceCategories:
        rootResolver(
          {
            .
            "excludeEmpty": option(bool),
            "excludeSubcategories": option(bool),
            "includeCategories": option(array(string)),
          },
          marketplaceCategory,
          array(marketplaceCategory),
        ),
      marketplaceCategory:
        rootResolver(
          {
            .
            "slug": string,
            "useTopicAliases": option(bool),
          },
          marketplaceCategory,
          option(marketplaceCategory),
        ),
      marketplaceListing:
        rootResolver(
          {. "slug": string},
          marketplaceListing,
          option(marketplaceListing),
        ),
      marketplaceListings:
        rootResolver(
          {
            .
            "adminId": option(string),
            "after": option(string),
            "allStates": option(bool),
            "before": option(string),
            "categorySlug": option(string),
            "first": option(int),
            "last": option(int),
            "organizationId": option(string),
            "primaryCategoryOnly": option(bool),
            "slugs": option(array(option(string))),
            "useTopicAliases": option(bool),
            "viewerCanAdmin": option(bool),
            "withFreeTrialsOnly": option(bool),
          },
          marketplaceListingConnection,
          marketplaceListingConnection,
        ),
      meta: rootResolver(unit, gitHubMetadata, gitHubMetadata),
      node: rootResolver({. "id": string}, node, option(node)),
      nodes:
        rootResolver({. "ids": array(string)}, node, array(option(node))),
      organization:
        rootResolver(
          {. "login": string},
          organization,
          option(organization),
        ),
      rateLimit:
        rootResolver(
          {. "dryRun": option(bool)},
          rateLimit,
          option(rateLimit),
        ),
      relay: rootResolver(unit, query, query),
      repository:
        rootResolver(
          {
            .
            "name": string,
            "owner": string,
          },
          repository,
          option(repository),
        ),
      repositoryOwner:
        rootResolver(
          {. "login": string},
          repositoryOwner,
          option(repositoryOwner),
        ),
      resource:
        rootResolver(
          {. "url": uRI},
          uniformResourceLocatable,
          option(uniformResourceLocatable),
        ),
      search:
        rootResolver(
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "query": string,
            "type": searchType,
          },
          searchResultItemConnection,
          searchResultItemConnection,
        ),
      topic: rootResolver({. "name": string}, topic, option(topic)),
      user: rootResolver({. "login": string}, user, option(user)),
      viewer: rootResolver(unit, user, user),
    };
  };
  module Mutation = {
    type t = {
      acceptTopicSuggestion:
        rootResolver(
          {. "input": acceptTopicSuggestionInput},
          acceptTopicSuggestionPayload,
          option(acceptTopicSuggestionPayload),
        ),
      addComment:
        rootResolver(
          {. "input": addCommentInput},
          addCommentPayload,
          option(addCommentPayload),
        ),
      addProjectCard:
        rootResolver(
          {. "input": addProjectCardInput},
          addProjectCardPayload,
          option(addProjectCardPayload),
        ),
      addProjectColumn:
        rootResolver(
          {. "input": addProjectColumnInput},
          addProjectColumnPayload,
          option(addProjectColumnPayload),
        ),
      addPullRequestReview:
        rootResolver(
          {. "input": addPullRequestReviewInput},
          addPullRequestReviewPayload,
          option(addPullRequestReviewPayload),
        ),
      addPullRequestReviewComment:
        rootResolver(
          {. "input": addPullRequestReviewCommentInput},
          addPullRequestReviewCommentPayload,
          option(addPullRequestReviewCommentPayload),
        ),
      addReaction:
        rootResolver(
          {. "input": addReactionInput},
          addReactionPayload,
          option(addReactionPayload),
        ),
      addStar:
        rootResolver(
          {. "input": addStarInput},
          addStarPayload,
          option(addStarPayload),
        ),
      createBranchProtectionRule:
        rootResolver(
          {. "input": createBranchProtectionRuleInput},
          createBranchProtectionRulePayload,
          option(createBranchProtectionRulePayload),
        ),
      createProject:
        rootResolver(
          {. "input": createProjectInput},
          createProjectPayload,
          option(createProjectPayload),
        ),
      declineTopicSuggestion:
        rootResolver(
          {. "input": declineTopicSuggestionInput},
          declineTopicSuggestionPayload,
          option(declineTopicSuggestionPayload),
        ),
      deleteBranchProtectionRule:
        rootResolver(
          {. "input": deleteBranchProtectionRuleInput},
          deleteBranchProtectionRulePayload,
          option(deleteBranchProtectionRulePayload),
        ),
      deleteProject:
        rootResolver(
          {. "input": deleteProjectInput},
          deleteProjectPayload,
          option(deleteProjectPayload),
        ),
      deleteProjectCard:
        rootResolver(
          {. "input": deleteProjectCardInput},
          deleteProjectCardPayload,
          option(deleteProjectCardPayload),
        ),
      deleteProjectColumn:
        rootResolver(
          {. "input": deleteProjectColumnInput},
          deleteProjectColumnPayload,
          option(deleteProjectColumnPayload),
        ),
      deletePullRequestReview:
        rootResolver(
          {. "input": deletePullRequestReviewInput},
          deletePullRequestReviewPayload,
          option(deletePullRequestReviewPayload),
        ),
      dismissPullRequestReview:
        rootResolver(
          {. "input": dismissPullRequestReviewInput},
          dismissPullRequestReviewPayload,
          option(dismissPullRequestReviewPayload),
        ),
      lockLockable:
        rootResolver(
          {. "input": lockLockableInput},
          lockLockablePayload,
          option(lockLockablePayload),
        ),
      moveProjectCard:
        rootResolver(
          {. "input": moveProjectCardInput},
          moveProjectCardPayload,
          option(moveProjectCardPayload),
        ),
      moveProjectColumn:
        rootResolver(
          {. "input": moveProjectColumnInput},
          moveProjectColumnPayload,
          option(moveProjectColumnPayload),
        ),
      removeOutsideCollaborator:
        rootResolver(
          {. "input": removeOutsideCollaboratorInput},
          removeOutsideCollaboratorPayload,
          option(removeOutsideCollaboratorPayload),
        ),
      removeReaction:
        rootResolver(
          {. "input": removeReactionInput},
          removeReactionPayload,
          option(removeReactionPayload),
        ),
      removeStar:
        rootResolver(
          {. "input": removeStarInput},
          removeStarPayload,
          option(removeStarPayload),
        ),
      requestReviews:
        rootResolver(
          {. "input": requestReviewsInput},
          requestReviewsPayload,
          option(requestReviewsPayload),
        ),
      submitPullRequestReview:
        rootResolver(
          {. "input": submitPullRequestReviewInput},
          submitPullRequestReviewPayload,
          option(submitPullRequestReviewPayload),
        ),
      unlockLockable:
        rootResolver(
          {. "input": unlockLockableInput},
          unlockLockablePayload,
          option(unlockLockablePayload),
        ),
      updateBranchProtectionRule:
        rootResolver(
          {. "input": updateBranchProtectionRuleInput},
          updateBranchProtectionRulePayload,
          option(updateBranchProtectionRulePayload),
        ),
      updateProject:
        rootResolver(
          {. "input": updateProjectInput},
          updateProjectPayload,
          option(updateProjectPayload),
        ),
      updateProjectCard:
        rootResolver(
          {. "input": updateProjectCardInput},
          updateProjectCardPayload,
          option(updateProjectCardPayload),
        ),
      updateProjectColumn:
        rootResolver(
          {. "input": updateProjectColumnInput},
          updateProjectColumnPayload,
          option(updateProjectColumnPayload),
        ),
      updatePullRequestReview:
        rootResolver(
          {. "input": updatePullRequestReviewInput},
          updatePullRequestReviewPayload,
          option(updatePullRequestReviewPayload),
        ),
      updatePullRequestReviewComment:
        rootResolver(
          {. "input": updatePullRequestReviewCommentInput},
          updatePullRequestReviewCommentPayload,
          option(updatePullRequestReviewCommentPayload),
        ),
      updateSubscription:
        rootResolver(
          {. "input": updateSubscriptionInput},
          updateSubscriptionPayload,
          option(updateSubscriptionPayload),
        ),
      updateTopics:
        rootResolver(
          {. "input": updateTopicsInput},
          updateTopicsPayload,
          option(updateTopicsPayload),
        ),
    };
  };
  module Subscription = {
    type t = {};
  };
  module Directives = {
    type t = {
      [@bs.as "include"]
      include_: directiveResolver({. "if": bool}),
      skip: directiveResolver({. "if": bool}),
      deprecated: directiveResolver({. "reason": option(string)}),
      specifiedBy: directiveResolver({. "url": string}),
    };
  };
  module ReferencedEvent = {
    type t = {
      actor: Config.resolver(referencedEvent, unit, actor, option(actor)),
      commit: Config.resolver(referencedEvent, unit, commit, option(commit)),
      commitRepository:
        Config.resolver(referencedEvent, unit, repository, repository),
      createdAt: Config.resolver(referencedEvent, unit, dateTime, dateTime),
      id: Config.resolver(referencedEvent, unit, string, string),
      isCrossRepository: Config.resolver(referencedEvent, unit, bool, bool),
      isDirectReference: Config.resolver(referencedEvent, unit, bool, bool),
      subject:
        Config.resolver(
          referencedEvent,
          unit,
          referencedSubject,
          referencedSubject,
        ),
    };
  };
  module MentionedEvent = {
    type t = {
      actor: Config.resolver(mentionedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(mentionedEvent, unit, dateTime, dateTime),
      databaseId: Config.resolver(mentionedEvent, unit, int, option(int)),
      id: Config.resolver(mentionedEvent, unit, string, string),
    };
  };
  module ReopenedEvent = {
    type t = {
      actor: Config.resolver(reopenedEvent, unit, actor, option(actor)),
      closable: Config.resolver(reopenedEvent, unit, closable, closable),
      createdAt: Config.resolver(reopenedEvent, unit, dateTime, dateTime),
      id: Config.resolver(reopenedEvent, unit, string, string),
    };
  };
  module ReviewDismissedEvent = {
    type t = {
      actor:
        Config.resolver(reviewDismissedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(reviewDismissedEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(reviewDismissedEvent, unit, int, option(int)),
      id: Config.resolver(reviewDismissedEvent, unit, string, string),
      message: Config.resolver(reviewDismissedEvent, unit, string, string),
      messageHtml: Config.resolver(reviewDismissedEvent, unit, hTML, hTML),
      previousReviewState:
        Config.resolver(
          reviewDismissedEvent,
          unit,
          pullRequestReviewState,
          pullRequestReviewState,
        ),
      pullRequest:
        Config.resolver(reviewDismissedEvent, unit, pullRequest, pullRequest),
      pullRequestCommit:
        Config.resolver(
          reviewDismissedEvent,
          unit,
          pullRequestCommit,
          option(pullRequestCommit),
        ),
      resourcePath: Config.resolver(reviewDismissedEvent, unit, uRI, uRI),
      review:
        Config.resolver(
          reviewDismissedEvent,
          unit,
          pullRequestReview,
          option(pullRequestReview),
        ),
      url: Config.resolver(reviewDismissedEvent, unit, uRI, uRI),
    };
  };
  module PullRequestReviewCommentEdge = {
    type t = {
      cursor:
        Config.resolver(pullRequestReviewCommentEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestReviewCommentEdge,
          unit,
          pullRequestReviewComment,
          option(pullRequestReviewComment),
        ),
    };
  };
  module UnknownSignature = {
    type t = {
      email: Config.resolver(unknownSignature, unit, string, string),
      isValid: Config.resolver(unknownSignature, unit, bool, bool),
      payload: Config.resolver(unknownSignature, unit, string, string),
      signature: Config.resolver(unknownSignature, unit, string, string),
      signer: Config.resolver(unknownSignature, unit, user, option(user)),
      state:
        Config.resolver(
          unknownSignature,
          unit,
          gitSignatureState,
          gitSignatureState,
        ),
      wasSignedByGitHub: Config.resolver(unknownSignature, unit, bool, bool),
    };
  };
  module IssueConnection = {
    type t = {
      edges:
        Config.resolver(
          issueConnection,
          unit,
          issueEdge,
          option(array(option(issueEdge))),
        ),
      nodes:
        Config.resolver(
          issueConnection,
          unit,
          issue,
          option(array(option(issue))),
        ),
      pageInfo: Config.resolver(issueConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(issueConnection, unit, int, int),
    };
  };
  module GistCommentEdge = {
    type t = {
      cursor: Config.resolver(gistCommentEdge, unit, string, string),
      node:
        Config.resolver(
          gistCommentEdge,
          unit,
          gistComment,
          option(gistComment),
        ),
    };
  };
  module PullRequestCommitConnection = {
    type t = {
      edges:
        Config.resolver(
          pullRequestCommitConnection,
          unit,
          pullRequestCommitEdge,
          option(array(option(pullRequestCommitEdge))),
        ),
      nodes:
        Config.resolver(
          pullRequestCommitConnection,
          unit,
          pullRequestCommit,
          option(array(option(pullRequestCommit))),
        ),
      pageInfo:
        Config.resolver(
          pullRequestCommitConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(pullRequestCommitConnection, unit, int, int),
    };
  };
  module SubscribedEvent = {
    type t = {
      actor: Config.resolver(subscribedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(subscribedEvent, unit, dateTime, dateTime),
      id: Config.resolver(subscribedEvent, unit, string, string),
      subscribable:
        Config.resolver(subscribedEvent, unit, subscribable, subscribable),
    };
  };
  module ExternalIdentitySamlAttributes = {
    type t = {
      nameId:
        Config.resolver(
          externalIdentitySamlAttributes,
          unit,
          string,
          option(string),
        ),
    };
  };
  module DeployKey = {
    type t = {
      createdAt: Config.resolver(deployKey, unit, dateTime, dateTime),
      id: Config.resolver(deployKey, unit, string, string),
      key: Config.resolver(deployKey, unit, string, string),
      readOnly: Config.resolver(deployKey, unit, bool, bool),
      title: Config.resolver(deployKey, unit, string, string),
      verified: Config.resolver(deployKey, unit, bool, bool),
    };
  };
  module Milestone = {
    type t = {
      closed: Config.resolver(milestone, unit, bool, bool),
      closedAt: Config.resolver(milestone, unit, dateTime, option(dateTime)),
      createdAt: Config.resolver(milestone, unit, dateTime, dateTime),
      creator: Config.resolver(milestone, unit, actor, option(actor)),
      description: Config.resolver(milestone, unit, string, option(string)),
      dueOn: Config.resolver(milestone, unit, dateTime, option(dateTime)),
      id: Config.resolver(milestone, unit, string, string),
      issues:
        Config.resolver(
          milestone,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(issueState)),
          },
          issueConnection,
          issueConnection,
        ),
      number: Config.resolver(milestone, unit, int, int),
      pullRequests:
        Config.resolver(
          milestone,
          {
            .
            "after": option(string),
            "baseRefName": option(string),
            "before": option(string),
            "first": option(int),
            "headRefName": option(string),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(pullRequestState)),
          },
          pullRequestConnection,
          pullRequestConnection,
        ),
      repository: Config.resolver(milestone, unit, repository, repository),
      resourcePath: Config.resolver(milestone, unit, uRI, uRI),
      state: Config.resolver(milestone, unit, milestoneState, milestoneState),
      title: Config.resolver(milestone, unit, string, string),
      updatedAt: Config.resolver(milestone, unit, dateTime, dateTime),
      url: Config.resolver(milestone, unit, uRI, uRI),
    };
  };
  module RepositoryTopicConnection = {
    type t = {
      edges:
        Config.resolver(
          repositoryTopicConnection,
          unit,
          repositoryTopicEdge,
          option(array(option(repositoryTopicEdge))),
        ),
      nodes:
        Config.resolver(
          repositoryTopicConnection,
          unit,
          repositoryTopic,
          option(array(option(repositoryTopic))),
        ),
      pageInfo:
        Config.resolver(repositoryTopicConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(repositoryTopicConnection, unit, int, int),
    };
  };
  module SmimeSignature = {
    type t = {
      email: Config.resolver(smimeSignature, unit, string, string),
      isValid: Config.resolver(smimeSignature, unit, bool, bool),
      payload: Config.resolver(smimeSignature, unit, string, string),
      signature: Config.resolver(smimeSignature, unit, string, string),
      signer: Config.resolver(smimeSignature, unit, user, option(user)),
      state:
        Config.resolver(
          smimeSignature,
          unit,
          gitSignatureState,
          gitSignatureState,
        ),
      wasSignedByGitHub: Config.resolver(smimeSignature, unit, bool, bool),
    };
  };
  module UpdatePullRequestReviewCommentPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          updatePullRequestReviewCommentPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReviewComment:
        Config.resolver(
          updatePullRequestReviewCommentPayload,
          unit,
          pullRequestReviewComment,
          pullRequestReviewComment,
        ),
    };
  };
  module LockLockablePayload = {
    type t = {
      clientMutationId:
        Config.resolver(lockLockablePayload, unit, string, option(string)),
      lockedRecord:
        Config.resolver(
          lockLockablePayload,
          unit,
          lockable,
          option(lockable),
        ),
    };
  };
  module ExternalIdentityScimAttributes = {
    type t = {
      username:
        Config.resolver(
          externalIdentityScimAttributes,
          unit,
          string,
          option(string),
        ),
    };
  };
  module RepositoryCollaboratorConnection = {
    type t = {
      edges:
        Config.resolver(
          repositoryCollaboratorConnection,
          unit,
          repositoryCollaboratorEdge,
          option(array(option(repositoryCollaboratorEdge))),
        ),
      nodes:
        Config.resolver(
          repositoryCollaboratorConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo:
        Config.resolver(
          repositoryCollaboratorConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(repositoryCollaboratorConnection, unit, int, int),
    };
  };
  module DeploymentConnection = {
    type t = {
      edges:
        Config.resolver(
          deploymentConnection,
          unit,
          deploymentEdge,
          option(array(option(deploymentEdge))),
        ),
      nodes:
        Config.resolver(
          deploymentConnection,
          unit,
          deployment,
          option(array(option(deployment))),
        ),
      pageInfo:
        Config.resolver(deploymentConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(deploymentConnection, unit, int, int),
    };
  };
  module GistConnection = {
    type t = {
      edges:
        Config.resolver(
          gistConnection,
          unit,
          gistEdge,
          option(array(option(gistEdge))),
        ),
      nodes:
        Config.resolver(
          gistConnection,
          unit,
          gist,
          option(array(option(gist))),
        ),
      pageInfo: Config.resolver(gistConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(gistConnection, unit, int, int),
    };
  };
  module MoveProjectCardPayload = {
    type t = {
      cardEdge:
        Config.resolver(
          moveProjectCardPayload,
          unit,
          projectCardEdge,
          projectCardEdge,
        ),
      clientMutationId:
        Config.resolver(
          moveProjectCardPayload,
          unit,
          string,
          option(string),
        ),
    };
  };
  module PullRequestTimelineItemsEdge = {
    type t = {
      cursor:
        Config.resolver(pullRequestTimelineItemsEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestTimelineItemsEdge,
          unit,
          pullRequestTimelineItems,
          option(pullRequestTimelineItems),
        ),
    };
  };
  module TextMatch = {
    type t = {
      fragment: Config.resolver(textMatch, unit, string, string),
      highlights:
        Config.resolver(
          textMatch,
          unit,
          textMatchHighlight,
          array(textMatchHighlight),
        ),
      property: Config.resolver(textMatch, unit, string, string),
    };
  };
  module AddCommentPayload = {
    type t = {
      clientMutationId:
        Config.resolver(addCommentPayload, unit, string, option(string)),
      commentEdge:
        Config.resolver(
          addCommentPayload,
          unit,
          issueCommentEdge,
          issueCommentEdge,
        ),
      subject: Config.resolver(addCommentPayload, unit, node, node),
      timelineEdge:
        Config.resolver(
          addCommentPayload,
          unit,
          issueTimelineItemEdge,
          issueTimelineItemEdge,
        ),
    };
  };
  module GitHubMetadata = {
    type t = {
      gitHubServicesSha:
        Config.resolver(gitHubMetadata, unit, gitObjectID, gitObjectID),
      gitIpAddresses:
        Config.resolver(
          gitHubMetadata,
          unit,
          string,
          option(array(string)),
        ),
      hookIpAddresses:
        Config.resolver(
          gitHubMetadata,
          unit,
          string,
          option(array(string)),
        ),
      importerIpAddresses:
        Config.resolver(
          gitHubMetadata,
          unit,
          string,
          option(array(string)),
        ),
      isPasswordAuthenticationVerifiable:
        Config.resolver(gitHubMetadata, unit, bool, bool),
      pagesIpAddresses:
        Config.resolver(
          gitHubMetadata,
          unit,
          string,
          option(array(string)),
        ),
    };
  };
  module StarredRepositoryConnection = {
    type t = {
      edges:
        Config.resolver(
          starredRepositoryConnection,
          unit,
          starredRepositoryEdge,
          option(array(option(starredRepositoryEdge))),
        ),
      nodes:
        Config.resolver(
          starredRepositoryConnection,
          unit,
          repository,
          option(array(option(repository))),
        ),
      pageInfo:
        Config.resolver(
          starredRepositoryConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(starredRepositoryConnection, unit, int, int),
    };
  };
  module UpdateSubscriptionPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          updateSubscriptionPayload,
          unit,
          string,
          option(string),
        ),
      subscribable:
        Config.resolver(
          updateSubscriptionPayload,
          unit,
          subscribable,
          subscribable,
        ),
    };
  };
  module CommentDeletedEvent = {
    type t = {
      actor:
        Config.resolver(commentDeletedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(commentDeletedEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(commentDeletedEvent, unit, int, option(int)),
      id: Config.resolver(commentDeletedEvent, unit, string, string),
    };
  };
  module TeamConnection = {
    type t = {
      edges:
        Config.resolver(
          teamConnection,
          unit,
          teamEdge,
          option(array(option(teamEdge))),
        ),
      nodes:
        Config.resolver(
          teamConnection,
          unit,
          team,
          option(array(option(team))),
        ),
      pageInfo: Config.resolver(teamConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(teamConnection, unit, int, int),
    };
  };
  module IssueTimelineItemsEdge = {
    type t = {
      cursor: Config.resolver(issueTimelineItemsEdge, unit, string, string),
      node:
        Config.resolver(
          issueTimelineItemsEdge,
          unit,
          issueTimelineItems,
          option(issueTimelineItems),
        ),
    };
  };
  module Topic = {
    type t = {
      id: Config.resolver(topic, unit, string, string),
      name: Config.resolver(topic, unit, string, string),
      relatedTopics: Config.resolver(topic, unit, topic, array(topic)),
      stargazers:
        Config.resolver(
          topic,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(starOrder),
          },
          stargazerConnection,
          stargazerConnection,
        ),
      viewerHasStarred: Config.resolver(topic, unit, bool, bool),
    };
  };
  module OrganizationInvitationConnection = {
    type t = {
      edges:
        Config.resolver(
          organizationInvitationConnection,
          unit,
          organizationInvitationEdge,
          option(array(option(organizationInvitationEdge))),
        ),
      nodes:
        Config.resolver(
          organizationInvitationConnection,
          unit,
          organizationInvitation,
          option(array(option(organizationInvitation))),
        ),
      pageInfo:
        Config.resolver(
          organizationInvitationConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(organizationInvitationConnection, unit, int, int),
    };
  };
  module Label = {
    type t = {
      color: Config.resolver(label, unit, string, string),
      createdAt: Config.resolver(label, unit, dateTime, option(dateTime)),
      description: Config.resolver(label, unit, string, option(string)),
      id: Config.resolver(label, unit, string, string),
      isDefault: Config.resolver(label, unit, bool, bool),
      issues:
        Config.resolver(
          label,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(issueState)),
          },
          issueConnection,
          issueConnection,
        ),
      name: Config.resolver(label, unit, string, string),
      pullRequests:
        Config.resolver(
          label,
          {
            .
            "after": option(string),
            "baseRefName": option(string),
            "before": option(string),
            "first": option(int),
            "headRefName": option(string),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(pullRequestState)),
          },
          pullRequestConnection,
          pullRequestConnection,
        ),
      repository: Config.resolver(label, unit, repository, repository),
      resourcePath: Config.resolver(label, unit, uRI, uRI),
      updatedAt: Config.resolver(label, unit, dateTime, option(dateTime)),
      url: Config.resolver(label, unit, uRI, uRI),
    };
  };
  module ReviewRequestEdge = {
    type t = {
      cursor: Config.resolver(reviewRequestEdge, unit, string, string),
      node:
        Config.resolver(
          reviewRequestEdge,
          unit,
          reviewRequest,
          option(reviewRequest),
        ),
    };
  };
  module UnlabeledEvent = {
    type t = {
      actor: Config.resolver(unlabeledEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(unlabeledEvent, unit, dateTime, dateTime),
      id: Config.resolver(unlabeledEvent, unit, string, string),
      label: Config.resolver(unlabeledEvent, unit, label, label),
      labelable: Config.resolver(unlabeledEvent, unit, labelable, labelable),
    };
  };
  module StarredRepositoryEdge = {
    type t = {
      cursor: Config.resolver(starredRepositoryEdge, unit, string, string),
      node:
        Config.resolver(starredRepositoryEdge, unit, repository, repository),
      starredAt:
        Config.resolver(starredRepositoryEdge, unit, dateTime, dateTime),
    };
  };
  module DeploymentStatusConnection = {
    type t = {
      edges:
        Config.resolver(
          deploymentStatusConnection,
          unit,
          deploymentStatusEdge,
          option(array(option(deploymentStatusEdge))),
        ),
      nodes:
        Config.resolver(
          deploymentStatusConnection,
          unit,
          deploymentStatus,
          option(array(option(deploymentStatus))),
        ),
      pageInfo:
        Config.resolver(deploymentStatusConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(deploymentStatusConnection, unit, int, int),
    };
  };
  module GistCommentConnection = {
    type t = {
      edges:
        Config.resolver(
          gistCommentConnection,
          unit,
          gistCommentEdge,
          option(array(option(gistCommentEdge))),
        ),
      nodes:
        Config.resolver(
          gistCommentConnection,
          unit,
          gistComment,
          option(array(option(gistComment))),
        ),
      pageInfo:
        Config.resolver(gistCommentConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(gistCommentConnection, unit, int, int),
    };
  };
  module UserEdge = {
    type t = {
      cursor: Config.resolver(userEdge, unit, string, string),
      node: Config.resolver(userEdge, unit, user, option(user)),
    };
  };
  module LicenseRule = {
    type t = {
      description: Config.resolver(licenseRule, unit, string, string),
      key: Config.resolver(licenseRule, unit, string, string),
      label: Config.resolver(licenseRule, unit, string, string),
    };
  };
  module ReleaseEdge = {
    type t = {
      cursor: Config.resolver(releaseEdge, unit, string, string),
      node: Config.resolver(releaseEdge, unit, release, option(release)),
    };
  };
  module RepositoryConnection = {
    type t = {
      edges:
        Config.resolver(
          repositoryConnection,
          unit,
          repositoryEdge,
          option(array(option(repositoryEdge))),
        ),
      nodes:
        Config.resolver(
          repositoryConnection,
          unit,
          repository,
          option(array(option(repository))),
        ),
      pageInfo:
        Config.resolver(repositoryConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(repositoryConnection, unit, int, int),
      totalDiskUsage: Config.resolver(repositoryConnection, unit, int, int),
    };
  };
  module ProjectCardEdge = {
    type t = {
      cursor: Config.resolver(projectCardEdge, unit, string, string),
      node:
        Config.resolver(
          projectCardEdge,
          unit,
          projectCard,
          option(projectCard),
        ),
    };
  };
  module OrganizationEdge = {
    type t = {
      cursor: Config.resolver(organizationEdge, unit, string, string),
      node:
        Config.resolver(
          organizationEdge,
          unit,
          organization,
          option(organization),
        ),
    };
  };
  module ReviewRequestedEvent = {
    type t = {
      actor:
        Config.resolver(reviewRequestedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(reviewRequestedEvent, unit, dateTime, dateTime),
      id: Config.resolver(reviewRequestedEvent, unit, string, string),
      pullRequest:
        Config.resolver(reviewRequestedEvent, unit, pullRequest, pullRequest),
      requestedReviewer:
        Config.resolver(
          reviewRequestedEvent,
          unit,
          requestedReviewer,
          option(requestedReviewer),
        ),
    };
  };
  module AddedToProjectEvent = {
    type t = {
      actor:
        Config.resolver(addedToProjectEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(addedToProjectEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(addedToProjectEvent, unit, int, option(int)),
      id: Config.resolver(addedToProjectEvent, unit, string, string),
    };
  };
  module ReleaseAssetEdge = {
    type t = {
      cursor: Config.resolver(releaseAssetEdge, unit, string, string),
      node:
        Config.resolver(
          releaseAssetEdge,
          unit,
          releaseAsset,
          option(releaseAsset),
        ),
    };
  };
  module Issue = {
    type t = {
      activeLockReason:
        Config.resolver(issue, unit, lockReason, option(lockReason)),
      assignees:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      author: Config.resolver(issue, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          issue,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(issue, unit, string, string),
      bodyHTML: Config.resolver(issue, unit, hTML, hTML),
      bodyText: Config.resolver(issue, unit, string, string),
      closed: Config.resolver(issue, unit, bool, bool),
      closedAt: Config.resolver(issue, unit, dateTime, option(dateTime)),
      comments:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          issueCommentConnection,
          issueCommentConnection,
        ),
      createdAt: Config.resolver(issue, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(issue, unit, bool, bool),
      databaseId: Config.resolver(issue, unit, int, option(int)),
      editor: Config.resolver(issue, unit, actor, option(actor)),
      id: Config.resolver(issue, unit, string, string),
      includesCreatedEdit: Config.resolver(issue, unit, bool, bool),
      labels:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          labelConnection,
          option(labelConnection),
        ),
      lastEditedAt: Config.resolver(issue, unit, dateTime, option(dateTime)),
      locked: Config.resolver(issue, unit, bool, bool),
      milestone: Config.resolver(issue, unit, milestone, option(milestone)),
      number: Config.resolver(issue, unit, int, int),
      participants:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      projectCards:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "archivedStates":
              option(array(option(projectCardArchivedState))),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          projectCardConnection,
          projectCardConnection,
        ),
      publishedAt: Config.resolver(issue, unit, dateTime, option(dateTime)),
      reactionGroups:
        Config.resolver(
          issue,
          unit,
          reactionGroup,
          option(array(reactionGroup)),
        ),
      reactions:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "content": option(reactionContent),
            "first": option(int),
            "last": option(int),
            "orderBy": option(reactionOrder),
          },
          reactionConnection,
          reactionConnection,
        ),
      repository: Config.resolver(issue, unit, repository, repository),
      resourcePath: Config.resolver(issue, unit, uRI, uRI),
      state: Config.resolver(issue, unit, issueState, issueState),
      timeline:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "since": option(dateTime),
          },
          issueTimelineConnection,
          issueTimelineConnection,
        ),
      title: Config.resolver(issue, unit, string, string),
      updatedAt: Config.resolver(issue, unit, dateTime, dateTime),
      url: Config.resolver(issue, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          issue,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanReact: Config.resolver(issue, unit, bool, bool),
      viewerCanSubscribe: Config.resolver(issue, unit, bool, bool),
      viewerCanUpdate: Config.resolver(issue, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          issue,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(issue, unit, bool, bool),
      viewerSubscription:
        Config.resolver(
          issue,
          unit,
          subscriptionState,
          option(subscriptionState),
        ),
    };
  };
  module ReactionConnection = {
    type t = {
      edges:
        Config.resolver(
          reactionConnection,
          unit,
          reactionEdge,
          option(array(option(reactionEdge))),
        ),
      nodes:
        Config.resolver(
          reactionConnection,
          unit,
          reaction,
          option(array(option(reaction))),
        ),
      pageInfo: Config.resolver(reactionConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(reactionConnection, unit, int, int),
      viewerHasReacted: Config.resolver(reactionConnection, unit, bool, bool),
    };
  };
  module IssueTimelineConnection = {
    type t = {
      edges:
        Config.resolver(
          issueTimelineConnection,
          unit,
          issueTimelineItemEdge,
          option(array(option(issueTimelineItemEdge))),
        ),
      nodes:
        Config.resolver(
          issueTimelineConnection,
          unit,
          issueTimelineItem,
          option(array(option(issueTimelineItem))),
        ),
      pageInfo:
        Config.resolver(issueTimelineConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(issueTimelineConnection, unit, int, int),
    };
  };
  module RepositoryTopic = {
    type t = {
      id: Config.resolver(repositoryTopic, unit, string, string),
      resourcePath: Config.resolver(repositoryTopic, unit, uRI, uRI),
      topic: Config.resolver(repositoryTopic, unit, topic, topic),
      url: Config.resolver(repositoryTopic, unit, uRI, uRI),
    };
  };
  module MarketplaceListingConnection = {
    type t = {
      edges:
        Config.resolver(
          marketplaceListingConnection,
          unit,
          marketplaceListingEdge,
          option(array(option(marketplaceListingEdge))),
        ),
      nodes:
        Config.resolver(
          marketplaceListingConnection,
          unit,
          marketplaceListing,
          option(array(option(marketplaceListing))),
        ),
      pageInfo:
        Config.resolver(
          marketplaceListingConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(marketplaceListingConnection, unit, int, int),
    };
  };
  module Commit = {
    type t = {
      abbreviatedOid: Config.resolver(commit, unit, string, string),
      additions: Config.resolver(commit, unit, int, int),
      author: Config.resolver(commit, unit, gitActor, option(gitActor)),
      authoredByCommitter: Config.resolver(commit, unit, bool, bool),
      authoredDate: Config.resolver(commit, unit, dateTime, dateTime),
      blame: Config.resolver(commit, {. "path": string}, blame, blame),
      changedFiles: Config.resolver(commit, unit, int, int),
      comments:
        Config.resolver(
          commit,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          commitCommentConnection,
          commitCommentConnection,
        ),
      commitResourcePath: Config.resolver(commit, unit, uRI, uRI),
      commitUrl: Config.resolver(commit, unit, uRI, uRI),
      committedDate: Config.resolver(commit, unit, dateTime, dateTime),
      committedViaWeb: Config.resolver(commit, unit, bool, bool),
      committer: Config.resolver(commit, unit, gitActor, option(gitActor)),
      deletions: Config.resolver(commit, unit, int, int),
      history:
        Config.resolver(
          commit,
          {
            .
            "after": option(string),
            "author": option(commitAuthor),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "path": option(string),
            "since": option(gitTimestamp),
            "until": option(gitTimestamp),
          },
          commitHistoryConnection,
          commitHistoryConnection,
        ),
      id: Config.resolver(commit, unit, string, string),
      message: Config.resolver(commit, unit, string, string),
      messageBody: Config.resolver(commit, unit, string, string),
      messageBodyHTML: Config.resolver(commit, unit, hTML, hTML),
      messageHeadline: Config.resolver(commit, unit, string, string),
      messageHeadlineHTML: Config.resolver(commit, unit, hTML, hTML),
      oid: Config.resolver(commit, unit, gitObjectID, gitObjectID),
      parents:
        Config.resolver(
          commit,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          commitConnection,
          commitConnection,
        ),
      pushedDate: Config.resolver(commit, unit, dateTime, option(dateTime)),
      repository: Config.resolver(commit, unit, repository, repository),
      resourcePath: Config.resolver(commit, unit, uRI, uRI),
      signature:
        Config.resolver(commit, unit, gitSignature, option(gitSignature)),
      status: Config.resolver(commit, unit, status, option(status)),
      tarballUrl: Config.resolver(commit, unit, uRI, uRI),
      tree: Config.resolver(commit, unit, tree, tree),
      treeResourcePath: Config.resolver(commit, unit, uRI, uRI),
      treeUrl: Config.resolver(commit, unit, uRI, uRI),
      url: Config.resolver(commit, unit, uRI, uRI),
      viewerCanSubscribe: Config.resolver(commit, unit, bool, bool),
      viewerSubscription:
        Config.resolver(
          commit,
          unit,
          subscriptionState,
          option(subscriptionState),
        ),
      zipballUrl: Config.resolver(commit, unit, uRI, uRI),
    };
  };
  module FollowerConnection = {
    type t = {
      edges:
        Config.resolver(
          followerConnection,
          unit,
          userEdge,
          option(array(option(userEdge))),
        ),
      nodes:
        Config.resolver(
          followerConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo: Config.resolver(followerConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(followerConnection, unit, int, int),
    };
  };
  module Project = {
    type t = {
      body: Config.resolver(project, unit, string, option(string)),
      bodyHTML: Config.resolver(project, unit, hTML, hTML),
      closed: Config.resolver(project, unit, bool, bool),
      closedAt: Config.resolver(project, unit, dateTime, option(dateTime)),
      columns:
        Config.resolver(
          project,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          projectColumnConnection,
          projectColumnConnection,
        ),
      createdAt: Config.resolver(project, unit, dateTime, dateTime),
      creator: Config.resolver(project, unit, actor, option(actor)),
      databaseId: Config.resolver(project, unit, int, option(int)),
      id: Config.resolver(project, unit, string, string),
      name: Config.resolver(project, unit, string, string),
      number: Config.resolver(project, unit, int, int),
      owner: Config.resolver(project, unit, projectOwner, projectOwner),
      pendingCards:
        Config.resolver(
          project,
          {
            .
            "after": option(string),
            "archivedStates":
              option(array(option(projectCardArchivedState))),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          projectCardConnection,
          projectCardConnection,
        ),
      resourcePath: Config.resolver(project, unit, uRI, uRI),
      state: Config.resolver(project, unit, projectState, projectState),
      updatedAt: Config.resolver(project, unit, dateTime, dateTime),
      url: Config.resolver(project, unit, uRI, uRI),
      viewerCanUpdate: Config.resolver(project, unit, bool, bool),
    };
  };
  module UserContentEditConnection = {
    type t = {
      edges:
        Config.resolver(
          userContentEditConnection,
          unit,
          userContentEditEdge,
          option(array(option(userContentEditEdge))),
        ),
      nodes:
        Config.resolver(
          userContentEditConnection,
          unit,
          userContentEdit,
          option(array(option(userContentEdit))),
        ),
      pageInfo:
        Config.resolver(userContentEditConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(userContentEditConnection, unit, int, int),
    };
  };
  module ReactionGroup = {
    type t = {
      content:
        Config.resolver(
          reactionGroup,
          unit,
          reactionContent,
          reactionContent,
        ),
      createdAt:
        Config.resolver(reactionGroup, unit, dateTime, option(dateTime)),
      subject: Config.resolver(reactionGroup, unit, reactable, reactable),
      users:
        Config.resolver(
          reactionGroup,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          reactingUserConnection,
          reactingUserConnection,
        ),
      viewerHasReacted: Config.resolver(reactionGroup, unit, bool, bool),
    };
  };
  module MergedEvent = {
    type t = {
      actor: Config.resolver(mergedEvent, unit, actor, option(actor)),
      commit: Config.resolver(mergedEvent, unit, commit, option(commit)),
      createdAt: Config.resolver(mergedEvent, unit, dateTime, dateTime),
      id: Config.resolver(mergedEvent, unit, string, string),
      mergeRef: Config.resolver(mergedEvent, unit, ref, option(ref)),
      mergeRefName: Config.resolver(mergedEvent, unit, string, string),
      pullRequest:
        Config.resolver(mergedEvent, unit, pullRequest, pullRequest),
      resourcePath: Config.resolver(mergedEvent, unit, uRI, uRI),
      url: Config.resolver(mergedEvent, unit, uRI, uRI),
    };
  };
  module ProtectedBranch = {
    type t = {
      creator: Config.resolver(protectedBranch, unit, actor, option(actor)),
      hasDismissableStaleReviews:
        Config.resolver(protectedBranch, unit, bool, bool),
      hasRequiredReviews: Config.resolver(protectedBranch, unit, bool, bool),
      hasRequiredStatusChecks:
        Config.resolver(protectedBranch, unit, bool, bool),
      hasRestrictedPushes: Config.resolver(protectedBranch, unit, bool, bool),
      hasRestrictedReviewDismissals:
        Config.resolver(protectedBranch, unit, bool, bool),
      hasStrictRequiredStatusChecks:
        Config.resolver(protectedBranch, unit, bool, bool),
      id: Config.resolver(protectedBranch, unit, string, string),
      isAdminEnforced: Config.resolver(protectedBranch, unit, bool, bool),
      name: Config.resolver(protectedBranch, unit, string, string),
      pushAllowances:
        Config.resolver(
          protectedBranch,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          pushAllowanceConnection,
          pushAllowanceConnection,
        ),
      repository:
        Config.resolver(protectedBranch, unit, repository, repository),
      requiredStatusCheckContexts:
        Config.resolver(
          protectedBranch,
          unit,
          string,
          option(array(option(string))),
        ),
      reviewDismissalAllowances:
        Config.resolver(
          protectedBranch,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          reviewDismissalAllowanceConnection,
          reviewDismissalAllowanceConnection,
        ),
    };
  };
  module DeployKeyEdge = {
    type t = {
      cursor: Config.resolver(deployKeyEdge, unit, string, string),
      node:
        Config.resolver(deployKeyEdge, unit, deployKey, option(deployKey)),
    };
  };
  module DeploymentEnvironmentChangedEvent = {
    type t = {
      actor:
        Config.resolver(
          deploymentEnvironmentChangedEvent,
          unit,
          actor,
          option(actor),
        ),
      createdAt:
        Config.resolver(
          deploymentEnvironmentChangedEvent,
          unit,
          dateTime,
          dateTime,
        ),
      deploymentStatus:
        Config.resolver(
          deploymentEnvironmentChangedEvent,
          unit,
          deploymentStatus,
          deploymentStatus,
        ),
      id:
        Config.resolver(
          deploymentEnvironmentChangedEvent,
          unit,
          string,
          string,
        ),
      pullRequest:
        Config.resolver(
          deploymentEnvironmentChangedEvent,
          unit,
          pullRequest,
          pullRequest,
        ),
    };
  };
  module CommitComment = {
    type t = {
      author: Config.resolver(commitComment, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          commitComment,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(commitComment, unit, string, string),
      bodyHTML: Config.resolver(commitComment, unit, hTML, hTML),
      bodyText: Config.resolver(commitComment, unit, string, string),
      commit: Config.resolver(commitComment, unit, commit, option(commit)),
      createdAt: Config.resolver(commitComment, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(commitComment, unit, bool, bool),
      databaseId: Config.resolver(commitComment, unit, int, option(int)),
      editor: Config.resolver(commitComment, unit, actor, option(actor)),
      id: Config.resolver(commitComment, unit, string, string),
      includesCreatedEdit: Config.resolver(commitComment, unit, bool, bool),
      lastEditedAt:
        Config.resolver(commitComment, unit, dateTime, option(dateTime)),
      path: Config.resolver(commitComment, unit, string, option(string)),
      position: Config.resolver(commitComment, unit, int, option(int)),
      publishedAt:
        Config.resolver(commitComment, unit, dateTime, option(dateTime)),
      reactionGroups:
        Config.resolver(
          commitComment,
          unit,
          reactionGroup,
          option(array(reactionGroup)),
        ),
      reactions:
        Config.resolver(
          commitComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "content": option(reactionContent),
            "first": option(int),
            "last": option(int),
            "orderBy": option(reactionOrder),
          },
          reactionConnection,
          reactionConnection,
        ),
      repository:
        Config.resolver(commitComment, unit, repository, repository),
      resourcePath: Config.resolver(commitComment, unit, uRI, uRI),
      updatedAt: Config.resolver(commitComment, unit, dateTime, dateTime),
      url: Config.resolver(commitComment, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          commitComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanDelete: Config.resolver(commitComment, unit, bool, bool),
      viewerCanReact: Config.resolver(commitComment, unit, bool, bool),
      viewerCanUpdate: Config.resolver(commitComment, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          commitComment,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(commitComment, unit, bool, bool),
    };
  };
  module ProtectedBranchEdge = {
    type t = {
      cursor: Config.resolver(protectedBranchEdge, unit, string, string),
      node:
        Config.resolver(
          protectedBranchEdge,
          unit,
          protectedBranch,
          option(protectedBranch),
        ),
    };
  };
  module RateLimit = {
    type t = {
      cost: Config.resolver(rateLimit, unit, int, int),
      limit: Config.resolver(rateLimit, unit, int, int),
      nodeCount: Config.resolver(rateLimit, unit, int, int),
      remaining: Config.resolver(rateLimit, unit, int, int),
      resetAt: Config.resolver(rateLimit, unit, dateTime, dateTime),
    };
  };
  module RemoveOutsideCollaboratorPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          removeOutsideCollaboratorPayload,
          unit,
          string,
          option(string),
        ),
      removedUser:
        Config.resolver(removeOutsideCollaboratorPayload, unit, user, user),
    };
  };
  module ClosedEvent = {
    type t = {
      actor: Config.resolver(closedEvent, unit, actor, option(actor)),
      closable: Config.resolver(closedEvent, unit, closable, closable),
      closer: Config.resolver(closedEvent, unit, closer, option(closer)),
      createdAt: Config.resolver(closedEvent, unit, dateTime, dateTime),
      id: Config.resolver(closedEvent, unit, string, string),
      resourcePath: Config.resolver(closedEvent, unit, uRI, uRI),
      url: Config.resolver(closedEvent, unit, uRI, uRI),
    };
  };
  module PullRequest = {
    type t = {
      activeLockReason:
        Config.resolver(pullRequest, unit, lockReason, option(lockReason)),
      additions: Config.resolver(pullRequest, unit, int, int),
      assignees:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      author: Config.resolver(pullRequest, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          pullRequest,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      baseRef: Config.resolver(pullRequest, unit, ref, option(ref)),
      baseRefName: Config.resolver(pullRequest, unit, string, string),
      baseRefOid:
        Config.resolver(pullRequest, unit, gitObjectID, gitObjectID),
      body: Config.resolver(pullRequest, unit, string, string),
      bodyHTML: Config.resolver(pullRequest, unit, hTML, hTML),
      bodyText: Config.resolver(pullRequest, unit, string, string),
      changedFiles: Config.resolver(pullRequest, unit, int, int),
      closed: Config.resolver(pullRequest, unit, bool, bool),
      closedAt:
        Config.resolver(pullRequest, unit, dateTime, option(dateTime)),
      comments:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          issueCommentConnection,
          issueCommentConnection,
        ),
      commits:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          pullRequestCommitConnection,
          pullRequestCommitConnection,
        ),
      createdAt: Config.resolver(pullRequest, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(pullRequest, unit, bool, bool),
      databaseId: Config.resolver(pullRequest, unit, int, option(int)),
      deletions: Config.resolver(pullRequest, unit, int, int),
      editor: Config.resolver(pullRequest, unit, actor, option(actor)),
      headRef: Config.resolver(pullRequest, unit, ref, option(ref)),
      headRefName: Config.resolver(pullRequest, unit, string, string),
      headRefOid:
        Config.resolver(pullRequest, unit, gitObjectID, gitObjectID),
      headRepository:
        Config.resolver(pullRequest, unit, repository, option(repository)),
      headRepositoryOwner:
        Config.resolver(
          pullRequest,
          unit,
          repositoryOwner,
          option(repositoryOwner),
        ),
      id: Config.resolver(pullRequest, unit, string, string),
      includesCreatedEdit: Config.resolver(pullRequest, unit, bool, bool),
      isCrossRepository: Config.resolver(pullRequest, unit, bool, bool),
      labels:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          labelConnection,
          option(labelConnection),
        ),
      lastEditedAt:
        Config.resolver(pullRequest, unit, dateTime, option(dateTime)),
      locked: Config.resolver(pullRequest, unit, bool, bool),
      maintainerCanModify: Config.resolver(pullRequest, unit, bool, bool),
      mergeCommit:
        Config.resolver(pullRequest, unit, commit, option(commit)),
      mergeable:
        Config.resolver(pullRequest, unit, mergeableState, mergeableState),
      merged: Config.resolver(pullRequest, unit, bool, bool),
      mergedAt:
        Config.resolver(pullRequest, unit, dateTime, option(dateTime)),
      mergedBy: Config.resolver(pullRequest, unit, actor, option(actor)),
      milestone:
        Config.resolver(pullRequest, unit, milestone, option(milestone)),
      number: Config.resolver(pullRequest, unit, int, int),
      participants:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      permalink: Config.resolver(pullRequest, unit, uRI, uRI),
      potentialMergeCommit:
        Config.resolver(pullRequest, unit, commit, option(commit)),
      projectCards:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "archivedStates":
              option(array(option(projectCardArchivedState))),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          projectCardConnection,
          projectCardConnection,
        ),
      publishedAt:
        Config.resolver(pullRequest, unit, dateTime, option(dateTime)),
      reactionGroups:
        Config.resolver(
          pullRequest,
          unit,
          reactionGroup,
          option(array(reactionGroup)),
        ),
      reactions:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "content": option(reactionContent),
            "first": option(int),
            "last": option(int),
            "orderBy": option(reactionOrder),
          },
          reactionConnection,
          reactionConnection,
        ),
      repository: Config.resolver(pullRequest, unit, repository, repository),
      resourcePath: Config.resolver(pullRequest, unit, uRI, uRI),
      revertResourcePath: Config.resolver(pullRequest, unit, uRI, uRI),
      revertUrl: Config.resolver(pullRequest, unit, uRI, uRI),
      reviewRequests:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          reviewRequestConnection,
          option(reviewRequestConnection),
        ),
      reviews:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "author": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "states": option(array(pullRequestReviewState)),
          },
          pullRequestReviewConnection,
          option(pullRequestReviewConnection),
        ),
      state:
        Config.resolver(
          pullRequest,
          unit,
          pullRequestState,
          pullRequestState,
        ),
      suggestedReviewers:
        Config.resolver(
          pullRequest,
          unit,
          suggestedReviewer,
          array(option(suggestedReviewer)),
        ),
      timeline:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "since": option(dateTime),
          },
          pullRequestTimelineConnection,
          pullRequestTimelineConnection,
        ),
      title: Config.resolver(pullRequest, unit, string, string),
      updatedAt: Config.resolver(pullRequest, unit, dateTime, dateTime),
      url: Config.resolver(pullRequest, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          pullRequest,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanApplySuggestion:
        Config.resolver(pullRequest, unit, bool, bool),
      viewerCanReact: Config.resolver(pullRequest, unit, bool, bool),
      viewerCanSubscribe: Config.resolver(pullRequest, unit, bool, bool),
      viewerCanUpdate: Config.resolver(pullRequest, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          pullRequest,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(pullRequest, unit, bool, bool),
      viewerSubscription:
        Config.resolver(
          pullRequest,
          unit,
          subscriptionState,
          option(subscriptionState),
        ),
    };
  };
  module Team = {
    type t = {
      ancestors:
        Config.resolver(
          team,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          teamConnection,
          teamConnection,
        ),
      avatarUrl:
        Config.resolver(team, {. "size": option(int)}, uRI, option(uRI)),
      childTeams:
        Config.resolver(
          team,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "immediateOnly": option(bool),
            "last": option(int),
            "orderBy": option(teamOrder),
            "userLogins": option(array(string)),
          },
          teamConnection,
          teamConnection,
        ),
      combinedSlug: Config.resolver(team, unit, string, string),
      createdAt: Config.resolver(team, unit, dateTime, dateTime),
      description: Config.resolver(team, unit, string, option(string)),
      editTeamResourcePath: Config.resolver(team, unit, uRI, uRI),
      editTeamUrl: Config.resolver(team, unit, uRI, uRI),
      id: Config.resolver(team, unit, string, string),
      invitations:
        Config.resolver(
          team,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          organizationInvitationConnection,
          option(organizationInvitationConnection),
        ),
      members:
        Config.resolver(
          team,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "membership": option(teamMembershipType),
            "orderBy": option(teamMemberOrder),
            "query": option(string),
            "role": option(teamMemberRole),
          },
          teamMemberConnection,
          teamMemberConnection,
        ),
      membersResourcePath: Config.resolver(team, unit, uRI, uRI),
      membersUrl: Config.resolver(team, unit, uRI, uRI),
      name: Config.resolver(team, unit, string, string),
      newTeamResourcePath: Config.resolver(team, unit, uRI, uRI),
      newTeamUrl: Config.resolver(team, unit, uRI, uRI),
      organization: Config.resolver(team, unit, organization, organization),
      parentTeam: Config.resolver(team, unit, team, option(team)),
      privacy: Config.resolver(team, unit, teamPrivacy, teamPrivacy),
      repositories:
        Config.resolver(
          team,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(teamRepositoryOrder),
            "query": option(string),
          },
          teamRepositoryConnection,
          teamRepositoryConnection,
        ),
      repositoriesResourcePath: Config.resolver(team, unit, uRI, uRI),
      repositoriesUrl: Config.resolver(team, unit, uRI, uRI),
      resourcePath: Config.resolver(team, unit, uRI, uRI),
      slug: Config.resolver(team, unit, string, string),
      teamsResourcePath: Config.resolver(team, unit, uRI, uRI),
      teamsUrl: Config.resolver(team, unit, uRI, uRI),
      updatedAt: Config.resolver(team, unit, dateTime, dateTime),
      url: Config.resolver(team, unit, uRI, uRI),
      viewerCanAdminister: Config.resolver(team, unit, bool, bool),
      viewerCanSubscribe: Config.resolver(team, unit, bool, bool),
      viewerSubscription:
        Config.resolver(
          team,
          unit,
          subscriptionState,
          option(subscriptionState),
        ),
    };
  };
  module UnlockedEvent = {
    type t = {
      actor: Config.resolver(unlockedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(unlockedEvent, unit, dateTime, dateTime),
      id: Config.resolver(unlockedEvent, unit, string, string),
      lockable: Config.resolver(unlockedEvent, unit, lockable, lockable),
    };
  };
  module ExternalIdentity = {
    type t = {
      guid: Config.resolver(externalIdentity, unit, string, string),
      id: Config.resolver(externalIdentity, unit, string, string),
      organizationInvitation:
        Config.resolver(
          externalIdentity,
          unit,
          organizationInvitation,
          option(organizationInvitation),
        ),
      samlIdentity:
        Config.resolver(
          externalIdentity,
          unit,
          externalIdentitySamlAttributes,
          option(externalIdentitySamlAttributes),
        ),
      scimIdentity:
        Config.resolver(
          externalIdentity,
          unit,
          externalIdentityScimAttributes,
          option(externalIdentityScimAttributes),
        ),
      user: Config.resolver(externalIdentity, unit, user, option(user)),
    };
  };
  module UpdatePullRequestReviewPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          updatePullRequestReviewPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReview:
        Config.resolver(
          updatePullRequestReviewPayload,
          unit,
          pullRequestReview,
          pullRequestReview,
        ),
    };
  };
  module AppEdge = {
    type t = {
      cursor: Config.resolver(appEdge, unit, string, string),
      node: Config.resolver(appEdge, unit, app, option(app)),
    };
  };
  module SubmitPullRequestReviewPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          submitPullRequestReviewPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReview:
        Config.resolver(
          submitPullRequestReviewPayload,
          unit,
          pullRequestReview,
          pullRequestReview,
        ),
    };
  };
  module DeploymentStatus = {
    type t = {
      createdAt: Config.resolver(deploymentStatus, unit, dateTime, dateTime),
      creator: Config.resolver(deploymentStatus, unit, actor, option(actor)),
      deployment:
        Config.resolver(deploymentStatus, unit, deployment, deployment),
      description:
        Config.resolver(deploymentStatus, unit, string, option(string)),
      environmentUrl:
        Config.resolver(deploymentStatus, unit, uRI, option(uRI)),
      id: Config.resolver(deploymentStatus, unit, string, string),
      logUrl: Config.resolver(deploymentStatus, unit, uRI, option(uRI)),
      state:
        Config.resolver(
          deploymentStatus,
          unit,
          deploymentStatusState,
          deploymentStatusState,
        ),
      updatedAt: Config.resolver(deploymentStatus, unit, dateTime, dateTime),
    };
  };
  module DismissPullRequestReviewPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          dismissPullRequestReviewPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReview:
        Config.resolver(
          dismissPullRequestReviewPayload,
          unit,
          pullRequestReview,
          pullRequestReview,
        ),
    };
  };
  module OrganizationInvitation = {
    type t = {
      createdAt:
        Config.resolver(organizationInvitation, unit, dateTime, dateTime),
      email:
        Config.resolver(
          organizationInvitation,
          unit,
          string,
          option(string),
        ),
      id: Config.resolver(organizationInvitation, unit, string, string),
      invitationType:
        Config.resolver(
          organizationInvitation,
          unit,
          organizationInvitationType,
          organizationInvitationType,
        ),
      invitee:
        Config.resolver(organizationInvitation, unit, user, option(user)),
      inviter: Config.resolver(organizationInvitation, unit, user, user),
      organization:
        Config.resolver(
          organizationInvitation,
          unit,
          organization,
          organization,
        ),
      role:
        Config.resolver(
          organizationInvitation,
          unit,
          organizationInvitationRole,
          organizationInvitationRole,
        ),
    };
  };
  module PullRequestReviewComment = {
    type t = {
      author:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          actor,
          option(actor),
        ),
      authorAssociation:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(pullRequestReviewComment, unit, string, string),
      bodyHTML: Config.resolver(pullRequestReviewComment, unit, hTML, hTML),
      bodyText:
        Config.resolver(pullRequestReviewComment, unit, string, string),
      commit: Config.resolver(pullRequestReviewComment, unit, commit, commit),
      createdAt:
        Config.resolver(pullRequestReviewComment, unit, dateTime, dateTime),
      createdViaEmail:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
      databaseId:
        Config.resolver(pullRequestReviewComment, unit, int, option(int)),
      diffHunk:
        Config.resolver(pullRequestReviewComment, unit, string, string),
      draftedAt:
        Config.resolver(pullRequestReviewComment, unit, dateTime, dateTime),
      editor:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          actor,
          option(actor),
        ),
      id: Config.resolver(pullRequestReviewComment, unit, string, string),
      includesCreatedEdit:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
      lastEditedAt:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          dateTime,
          option(dateTime),
        ),
      originalCommit:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          commit,
          option(commit),
        ),
      originalPosition:
        Config.resolver(pullRequestReviewComment, unit, int, int),
      outdated: Config.resolver(pullRequestReviewComment, unit, bool, bool),
      path: Config.resolver(pullRequestReviewComment, unit, string, string),
      position:
        Config.resolver(pullRequestReviewComment, unit, int, option(int)),
      publishedAt:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          dateTime,
          option(dateTime),
        ),
      pullRequest:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          pullRequest,
          pullRequest,
        ),
      pullRequestReview:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          pullRequestReview,
          option(pullRequestReview),
        ),
      reactionGroups:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          reactionGroup,
          option(array(reactionGroup)),
        ),
      reactions:
        Config.resolver(
          pullRequestReviewComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "content": option(reactionContent),
            "first": option(int),
            "last": option(int),
            "orderBy": option(reactionOrder),
          },
          reactionConnection,
          reactionConnection,
        ),
      replyTo:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          pullRequestReviewComment,
          option(pullRequestReviewComment),
        ),
      repository:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          repository,
          repository,
        ),
      resourcePath: Config.resolver(pullRequestReviewComment, unit, uRI, uRI),
      state:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          pullRequestReviewCommentState,
          pullRequestReviewCommentState,
        ),
      updatedAt:
        Config.resolver(pullRequestReviewComment, unit, dateTime, dateTime),
      url: Config.resolver(pullRequestReviewComment, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          pullRequestReviewComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanDelete:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
      viewerCanReact:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
      viewerCanUpdate:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          pullRequestReviewComment,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor:
        Config.resolver(pullRequestReviewComment, unit, bool, bool),
    };
  };
  module Organization = {
    type t = {
      avatarUrl:
        Config.resolver(organization, {. "size": option(int)}, uRI, uRI),
      databaseId: Config.resolver(organization, unit, int, option(int)),
      description:
        Config.resolver(organization, unit, string, option(string)),
      email: Config.resolver(organization, unit, string, option(string)),
      id: Config.resolver(organization, unit, string, string),
      isVerified: Config.resolver(organization, unit, bool, bool),
      location: Config.resolver(organization, unit, string, option(string)),
      login: Config.resolver(organization, unit, string, string),
      members:
        Config.resolver(
          organization,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      name: Config.resolver(organization, unit, string, option(string)),
      newTeamResourcePath: Config.resolver(organization, unit, uRI, uRI),
      newTeamUrl: Config.resolver(organization, unit, uRI, uRI),
      organizationBillingEmail:
        Config.resolver(organization, unit, string, option(string)),
      pinnedRepositories:
        Config.resolver(
          organization,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      project:
        Config.resolver(
          organization,
          {. "number": int},
          project,
          option(project),
        ),
      projects:
        Config.resolver(
          organization,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(projectOrder),
            "search": option(string),
            "states": option(array(projectState)),
          },
          projectConnection,
          projectConnection,
        ),
      projectsResourcePath: Config.resolver(organization, unit, uRI, uRI),
      projectsUrl: Config.resolver(organization, unit, uRI, uRI),
      repositories:
        Config.resolver(
          organization,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isFork": option(bool),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      repository:
        Config.resolver(
          organization,
          {. "name": string},
          repository,
          option(repository),
        ),
      requiresTwoFactorAuthentication:
        Config.resolver(organization, unit, bool, option(bool)),
      resourcePath: Config.resolver(organization, unit, uRI, uRI),
      samlIdentityProvider:
        Config.resolver(
          organization,
          unit,
          organizationIdentityProvider,
          option(organizationIdentityProvider),
        ),
      team:
        Config.resolver(
          organization,
          {. "slug": string},
          team,
          option(team),
        ),
      teams:
        Config.resolver(
          organization,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "ldapMapped": option(bool),
            "orderBy": option(teamOrder),
            "privacy": option(teamPrivacy),
            "query": option(string),
            "role": option(teamRole),
            "rootTeamsOnly": option(bool),
            "userLogins": option(array(string)),
          },
          teamConnection,
          teamConnection,
        ),
      teamsResourcePath: Config.resolver(organization, unit, uRI, uRI),
      teamsUrl: Config.resolver(organization, unit, uRI, uRI),
      url: Config.resolver(organization, unit, uRI, uRI),
      viewerCanAdminister: Config.resolver(organization, unit, bool, bool),
      viewerCanCreateProjects:
        Config.resolver(organization, unit, bool, bool),
      viewerCanCreateRepositories:
        Config.resolver(organization, unit, bool, bool),
      viewerCanCreateTeams: Config.resolver(organization, unit, bool, bool),
      viewerIsAMember: Config.resolver(organization, unit, bool, bool),
      websiteUrl: Config.resolver(organization, unit, uRI, option(uRI)),
    };
  };
  module Blob = {
    type t = {
      abbreviatedOid: Config.resolver(blob, unit, string, string),
      byteSize: Config.resolver(blob, unit, int, int),
      commitResourcePath: Config.resolver(blob, unit, uRI, uRI),
      commitUrl: Config.resolver(blob, unit, uRI, uRI),
      id: Config.resolver(blob, unit, string, string),
      isBinary: Config.resolver(blob, unit, bool, bool),
      isTruncated: Config.resolver(blob, unit, bool, bool),
      oid: Config.resolver(blob, unit, gitObjectID, gitObjectID),
      repository: Config.resolver(blob, unit, repository, repository),
      text: Config.resolver(blob, unit, string, option(string)),
    };
  };
  module CreateBranchProtectionRulePayload = {
    type t = {
      branchProtectionRule:
        Config.resolver(
          createBranchProtectionRulePayload,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      clientMutationId:
        Config.resolver(
          createBranchProtectionRulePayload,
          unit,
          string,
          option(string),
        ),
    };
  };
  module MovedColumnsInProjectEvent = {
    type t = {
      actor:
        Config.resolver(
          movedColumnsInProjectEvent,
          unit,
          actor,
          option(actor),
        ),
      createdAt:
        Config.resolver(movedColumnsInProjectEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(movedColumnsInProjectEvent, unit, int, option(int)),
      id: Config.resolver(movedColumnsInProjectEvent, unit, string, string),
    };
  };
  module TeamMemberConnection = {
    type t = {
      edges:
        Config.resolver(
          teamMemberConnection,
          unit,
          teamMemberEdge,
          option(array(option(teamMemberEdge))),
        ),
      nodes:
        Config.resolver(
          teamMemberConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo:
        Config.resolver(teamMemberConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(teamMemberConnection, unit, int, int),
    };
  };
  module MarketplaceListingEdge = {
    type t = {
      cursor: Config.resolver(marketplaceListingEdge, unit, string, string),
      node:
        Config.resolver(
          marketplaceListingEdge,
          unit,
          marketplaceListing,
          option(marketplaceListing),
        ),
    };
  };
  module AcceptTopicSuggestionPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          acceptTopicSuggestionPayload,
          unit,
          string,
          option(string),
        ),
      topic:
        Config.resolver(acceptTopicSuggestionPayload, unit, topic, topic),
    };
  };
  module BranchProtectionRuleEdge = {
    type t = {
      cursor: Config.resolver(branchProtectionRuleEdge, unit, string, string),
      node:
        Config.resolver(
          branchProtectionRuleEdge,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
    };
  };
  module MoveProjectColumnPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          moveProjectColumnPayload,
          unit,
          string,
          option(string),
        ),
      columnEdge:
        Config.resolver(
          moveProjectColumnPayload,
          unit,
          projectColumnEdge,
          projectColumnEdge,
        ),
    };
  };
  module PushAllowanceEdge = {
    type t = {
      cursor: Config.resolver(pushAllowanceEdge, unit, string, string),
      node:
        Config.resolver(
          pushAllowanceEdge,
          unit,
          pushAllowance,
          option(pushAllowance),
        ),
    };
  };
  module LockedEvent = {
    type t = {
      actor: Config.resolver(lockedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(lockedEvent, unit, dateTime, dateTime),
      id: Config.resolver(lockedEvent, unit, string, string),
      lockReason:
        Config.resolver(lockedEvent, unit, lockReason, option(lockReason)),
      lockable: Config.resolver(lockedEvent, unit, lockable, lockable),
    };
  };
  module ReviewDismissalAllowanceEdge = {
    type t = {
      cursor:
        Config.resolver(reviewDismissalAllowanceEdge, unit, string, string),
      node:
        Config.resolver(
          reviewDismissalAllowanceEdge,
          unit,
          reviewDismissalAllowance,
          option(reviewDismissalAllowance),
        ),
    };
  };
  module UnlockLockablePayload = {
    type t = {
      clientMutationId:
        Config.resolver(unlockLockablePayload, unit, string, option(string)),
      unlockedRecord:
        Config.resolver(
          unlockLockablePayload,
          unit,
          lockable,
          option(lockable),
        ),
    };
  };
  module DeleteBranchProtectionRulePayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          deleteBranchProtectionRulePayload,
          unit,
          string,
          option(string),
        ),
    };
  };
  module UpdateTopicsPayload = {
    type t = {
      clientMutationId:
        Config.resolver(updateTopicsPayload, unit, string, option(string)),
      invalidTopicNames:
        Config.resolver(
          updateTopicsPayload,
          unit,
          string,
          option(array(string)),
        ),
      repository:
        Config.resolver(updateTopicsPayload, unit, repository, repository),
    };
  };
  module ProjectCardConnection = {
    type t = {
      edges:
        Config.resolver(
          projectCardConnection,
          unit,
          projectCardEdge,
          option(array(option(projectCardEdge))),
        ),
      nodes:
        Config.resolver(
          projectCardConnection,
          unit,
          projectCard,
          option(array(option(projectCard))),
        ),
      pageInfo:
        Config.resolver(projectCardConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(projectCardConnection, unit, int, int),
    };
  };
  module PullRequestReviewEdge = {
    type t = {
      cursor: Config.resolver(pullRequestReviewEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestReviewEdge,
          unit,
          pullRequestReview,
          option(pullRequestReview),
        ),
    };
  };
  module DeployedEvent = {
    type t = {
      actor: Config.resolver(deployedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(deployedEvent, unit, dateTime, dateTime),
      databaseId: Config.resolver(deployedEvent, unit, int, option(int)),
      deployment:
        Config.resolver(deployedEvent, unit, deployment, deployment),
      id: Config.resolver(deployedEvent, unit, string, string),
      pullRequest:
        Config.resolver(deployedEvent, unit, pullRequest, pullRequest),
      ref: Config.resolver(deployedEvent, unit, ref, option(ref)),
    };
  };
  module StargazerEdge = {
    type t = {
      cursor: Config.resolver(stargazerEdge, unit, string, string),
      node: Config.resolver(stargazerEdge, unit, user, user),
      starredAt: Config.resolver(stargazerEdge, unit, dateTime, dateTime),
    };
  };
  module Release = {
    type t = {
      author: Config.resolver(release, unit, user, option(user)),
      createdAt: Config.resolver(release, unit, dateTime, dateTime),
      description: Config.resolver(release, unit, string, option(string)),
      id: Config.resolver(release, unit, string, string),
      isDraft: Config.resolver(release, unit, bool, bool),
      isPrerelease: Config.resolver(release, unit, bool, bool),
      name: Config.resolver(release, unit, string, option(string)),
      publishedAt:
        Config.resolver(release, unit, dateTime, option(dateTime)),
      releaseAssets:
        Config.resolver(
          release,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "name": option(string),
          },
          releaseAssetConnection,
          releaseAssetConnection,
        ),
      resourcePath: Config.resolver(release, unit, uRI, uRI),
      tag: Config.resolver(release, unit, ref, option(ref)),
      updatedAt: Config.resolver(release, unit, dateTime, dateTime),
      url: Config.resolver(release, unit, uRI, uRI),
    };
  };
  module DeleteProjectCardPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          deleteProjectCardPayload,
          unit,
          string,
          option(string),
        ),
      column:
        Config.resolver(
          deleteProjectCardPayload,
          unit,
          projectColumn,
          projectColumn,
        ),
      deletedCardId:
        Config.resolver(deleteProjectCardPayload, unit, string, string),
    };
  };
  module RepositoryInvitation = {
    type t = {
      id: Config.resolver(repositoryInvitation, unit, string, string),
      invitee: Config.resolver(repositoryInvitation, unit, user, user),
      inviter: Config.resolver(repositoryInvitation, unit, user, user),
      permission:
        Config.resolver(
          repositoryInvitation,
          unit,
          repositoryPermission,
          repositoryPermission,
        ),
      repository:
        Config.resolver(
          repositoryInvitation,
          unit,
          repositoryInfo,
          option(repositoryInfo),
        ),
    };
  };
  module ProjectColumn = {
    type t = {
      cards:
        Config.resolver(
          projectColumn,
          {
            .
            "after": option(string),
            "archivedStates":
              option(array(option(projectCardArchivedState))),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          projectCardConnection,
          projectCardConnection,
        ),
      createdAt: Config.resolver(projectColumn, unit, dateTime, dateTime),
      databaseId: Config.resolver(projectColumn, unit, int, option(int)),
      id: Config.resolver(projectColumn, unit, string, string),
      name: Config.resolver(projectColumn, unit, string, string),
      project: Config.resolver(projectColumn, unit, project, project),
      purpose:
        Config.resolver(
          projectColumn,
          unit,
          projectColumnPurpose,
          option(projectColumnPurpose),
        ),
      resourcePath: Config.resolver(projectColumn, unit, uRI, uRI),
      updatedAt: Config.resolver(projectColumn, unit, dateTime, dateTime),
      url: Config.resolver(projectColumn, unit, uRI, uRI),
    };
  };
  module LabelConnection = {
    type t = {
      edges:
        Config.resolver(
          labelConnection,
          unit,
          labelEdge,
          option(array(option(labelEdge))),
        ),
      nodes:
        Config.resolver(
          labelConnection,
          unit,
          label,
          option(array(option(label))),
        ),
      pageInfo: Config.resolver(labelConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(labelConnection, unit, int, int),
    };
  };
  module MilestoneEdge = {
    type t = {
      cursor: Config.resolver(milestoneEdge, unit, string, string),
      node:
        Config.resolver(milestoneEdge, unit, milestone, option(milestone)),
    };
  };
  module RepositoryTopicEdge = {
    type t = {
      cursor: Config.resolver(repositoryTopicEdge, unit, string, string),
      node:
        Config.resolver(
          repositoryTopicEdge,
          unit,
          repositoryTopic,
          option(repositoryTopic),
        ),
    };
  };
  module UpdateProjectPayload = {
    type t = {
      clientMutationId:
        Config.resolver(updateProjectPayload, unit, string, option(string)),
      project: Config.resolver(updateProjectPayload, unit, project, project),
    };
  };
  module Repository = {
    type t = {
      assignableUsers:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      branchProtectionRules:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          branchProtectionRuleConnection,
          branchProtectionRuleConnection,
        ),
      codeOfConduct:
        Config.resolver(
          repository,
          unit,
          codeOfConduct,
          option(codeOfConduct),
        ),
      collaborators:
        Config.resolver(
          repository,
          {
            .
            "affiliation": option(collaboratorAffiliation),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          repositoryCollaboratorConnection,
          option(repositoryCollaboratorConnection),
        ),
      commitComments:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          commitCommentConnection,
          commitCommentConnection,
        ),
      createdAt: Config.resolver(repository, unit, dateTime, dateTime),
      databaseId: Config.resolver(repository, unit, int, option(int)),
      defaultBranchRef: Config.resolver(repository, unit, ref, option(ref)),
      deployKeys:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          deployKeyConnection,
          deployKeyConnection,
        ),
      deployments:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "environments": option(array(string)),
            "first": option(int),
            "last": option(int),
          },
          deploymentConnection,
          deploymentConnection,
        ),
      description: Config.resolver(repository, unit, string, option(string)),
      descriptionHTML: Config.resolver(repository, unit, hTML, hTML),
      diskUsage: Config.resolver(repository, unit, int, option(int)),
      forkCount: Config.resolver(repository, unit, int, int),
      forks:
        Config.resolver(
          repository,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      hasIssuesEnabled: Config.resolver(repository, unit, bool, bool),
      hasWikiEnabled: Config.resolver(repository, unit, bool, bool),
      homepageUrl: Config.resolver(repository, unit, uRI, option(uRI)),
      id: Config.resolver(repository, unit, string, string),
      isArchived: Config.resolver(repository, unit, bool, bool),
      isFork: Config.resolver(repository, unit, bool, bool),
      isLocked: Config.resolver(repository, unit, bool, bool),
      isMirror: Config.resolver(repository, unit, bool, bool),
      isPrivate: Config.resolver(repository, unit, bool, bool),
      issue:
        Config.resolver(
          repository,
          {. "number": int},
          issue,
          option(issue),
        ),
      issueOrPullRequest:
        Config.resolver(
          repository,
          {. "number": int},
          issueOrPullRequest,
          option(issueOrPullRequest),
        ),
      issues:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(issueState)),
          },
          issueConnection,
          issueConnection,
        ),
      label:
        Config.resolver(
          repository,
          {. "name": string},
          label,
          option(label),
        ),
      labels:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "query": option(string),
          },
          labelConnection,
          option(labelConnection),
        ),
      languages:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(languageOrder),
          },
          languageConnection,
          option(languageConnection),
        ),
      licenseInfo:
        Config.resolver(repository, unit, license, option(license)),
      lockReason:
        Config.resolver(
          repository,
          unit,
          repositoryLockReason,
          option(repositoryLockReason),
        ),
      mentionableUsers:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
      mergeCommitAllowed: Config.resolver(repository, unit, bool, bool),
      milestone:
        Config.resolver(
          repository,
          {. "number": int},
          milestone,
          option(milestone),
        ),
      milestones:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(milestoneOrder),
            "states": option(array(milestoneState)),
          },
          milestoneConnection,
          option(milestoneConnection),
        ),
      mirrorUrl: Config.resolver(repository, unit, uRI, option(uRI)),
      name: Config.resolver(repository, unit, string, string),
      nameWithOwner: Config.resolver(repository, unit, string, string),
      [@bs.as "object"]
      object_:
        Config.resolver(
          repository,
          {
            .
            "expression": option(string),
            "oid": option(gitObjectID),
          },
          gitObject,
          option(gitObject),
        ),
      owner:
        Config.resolver(repository, unit, repositoryOwner, repositoryOwner),
      parent:
        Config.resolver(repository, unit, repository, option(repository)),
      primaryLanguage:
        Config.resolver(repository, unit, language, option(language)),
      project:
        Config.resolver(
          repository,
          {. "number": int},
          project,
          option(project),
        ),
      projects:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(projectOrder),
            "search": option(string),
            "states": option(array(projectState)),
          },
          projectConnection,
          projectConnection,
        ),
      projectsResourcePath: Config.resolver(repository, unit, uRI, uRI),
      projectsUrl: Config.resolver(repository, unit, uRI, uRI),
      protectedBranches:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          protectedBranchConnection,
          protectedBranchConnection,
        ),
      pullRequest:
        Config.resolver(
          repository,
          {. "number": int},
          pullRequest,
          option(pullRequest),
        ),
      pullRequests:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "baseRefName": option(string),
            "before": option(string),
            "first": option(int),
            "headRefName": option(string),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(pullRequestState)),
          },
          pullRequestConnection,
          pullRequestConnection,
        ),
      pushedAt:
        Config.resolver(repository, unit, dateTime, option(dateTime)),
      rebaseMergeAllowed: Config.resolver(repository, unit, bool, bool),
      ref:
        Config.resolver(
          repository,
          {. "qualifiedName": string},
          ref,
          option(ref),
        ),
      refs:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "direction": option(orderDirection),
            "first": option(int),
            "last": option(int),
            "orderBy": option(refOrder),
            "refPrefix": string,
          },
          refConnection,
          option(refConnection),
        ),
      release:
        Config.resolver(
          repository,
          {. "tagName": string},
          release,
          option(release),
        ),
      releases:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(releaseOrder),
          },
          releaseConnection,
          releaseConnection,
        ),
      repositoryTopics:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          repositoryTopicConnection,
          repositoryTopicConnection,
        ),
      resourcePath: Config.resolver(repository, unit, uRI, uRI),
      shortDescriptionHTML:
        Config.resolver(repository, {. "limit": option(int)}, hTML, hTML),
      squashMergeAllowed: Config.resolver(repository, unit, bool, bool),
      sshUrl: Config.resolver(repository, unit, gitSSHRemote, gitSSHRemote),
      stargazers:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(starOrder),
          },
          stargazerConnection,
          stargazerConnection,
        ),
      updatedAt: Config.resolver(repository, unit, dateTime, dateTime),
      url: Config.resolver(repository, unit, uRI, uRI),
      viewerCanAdminister: Config.resolver(repository, unit, bool, bool),
      viewerCanCreateProjects: Config.resolver(repository, unit, bool, bool),
      viewerCanSubscribe: Config.resolver(repository, unit, bool, bool),
      viewerCanUpdateTopics: Config.resolver(repository, unit, bool, bool),
      viewerHasStarred: Config.resolver(repository, unit, bool, bool),
      viewerPermission:
        Config.resolver(
          repository,
          unit,
          repositoryPermission,
          option(repositoryPermission),
        ),
      viewerSubscription:
        Config.resolver(
          repository,
          unit,
          subscriptionState,
          option(subscriptionState),
        ),
      watchers:
        Config.resolver(
          repository,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userConnection,
          userConnection,
        ),
    };
  };
  module PullRequestReviewThread = {
    type t = {
      comments:
        Config.resolver(
          pullRequestReviewThread,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          pullRequestReviewCommentConnection,
          pullRequestReviewCommentConnection,
        ),
      id: Config.resolver(pullRequestReviewThread, unit, string, string),
      pullRequest:
        Config.resolver(
          pullRequestReviewThread,
          unit,
          pullRequest,
          pullRequest,
        ),
      repository:
        Config.resolver(
          pullRequestReviewThread,
          unit,
          repository,
          repository,
        ),
    };
  };
  module BranchProtectionRuleConflict = {
    type t = {
      branchProtectionRule:
        Config.resolver(
          branchProtectionRuleConflict,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      conflictingBranchProtectionRule:
        Config.resolver(
          branchProtectionRuleConflict,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      ref:
        Config.resolver(
          branchProtectionRuleConflict,
          unit,
          ref,
          option(ref),
        ),
    };
  };
  module AddReactionPayload = {
    type t = {
      clientMutationId:
        Config.resolver(addReactionPayload, unit, string, option(string)),
      reaction: Config.resolver(addReactionPayload, unit, reaction, reaction),
      subject:
        Config.resolver(addReactionPayload, unit, reactable, reactable),
    };
  };
  module BranchProtectionRuleConflictEdge = {
    type t = {
      cursor:
        Config.resolver(
          branchProtectionRuleConflictEdge,
          unit,
          string,
          string,
        ),
      node:
        Config.resolver(
          branchProtectionRuleConflictEdge,
          unit,
          branchProtectionRuleConflict,
          option(branchProtectionRuleConflict),
        ),
    };
  };
  module HeadRefDeletedEvent = {
    type t = {
      actor:
        Config.resolver(headRefDeletedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(headRefDeletedEvent, unit, dateTime, dateTime),
      headRef: Config.resolver(headRefDeletedEvent, unit, ref, option(ref)),
      headRefName: Config.resolver(headRefDeletedEvent, unit, string, string),
      id: Config.resolver(headRefDeletedEvent, unit, string, string),
      pullRequest:
        Config.resolver(headRefDeletedEvent, unit, pullRequest, pullRequest),
    };
  };
  module License = {
    type t = {
      body: Config.resolver(license, unit, string, string),
      conditions:
        Config.resolver(
          license,
          unit,
          licenseRule,
          array(option(licenseRule)),
        ),
      description: Config.resolver(license, unit, string, option(string)),
      featured: Config.resolver(license, unit, bool, bool),
      hidden: Config.resolver(license, unit, bool, bool),
      id: Config.resolver(license, unit, string, string),
      implementation: Config.resolver(license, unit, string, option(string)),
      key: Config.resolver(license, unit, string, string),
      limitations:
        Config.resolver(
          license,
          unit,
          licenseRule,
          array(option(licenseRule)),
        ),
      name: Config.resolver(license, unit, string, string),
      nickname: Config.resolver(license, unit, string, option(string)),
      permissions:
        Config.resolver(
          license,
          unit,
          licenseRule,
          array(option(licenseRule)),
        ),
      pseudoLicense: Config.resolver(license, unit, bool, bool),
      spdxId: Config.resolver(license, unit, string, option(string)),
      url: Config.resolver(license, unit, uRI, option(uRI)),
    };
  };
  module RemovedFromProjectEvent = {
    type t = {
      actor:
        Config.resolver(removedFromProjectEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(removedFromProjectEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(removedFromProjectEvent, unit, int, option(int)),
      id: Config.resolver(removedFromProjectEvent, unit, string, string),
    };
  };
  module IssueEdge = {
    type t = {
      cursor: Config.resolver(issueEdge, unit, string, string),
      node: Config.resolver(issueEdge, unit, issue, option(issue)),
    };
  };
  module ReviewRequestRemovedEvent = {
    type t = {
      actor:
        Config.resolver(
          reviewRequestRemovedEvent,
          unit,
          actor,
          option(actor),
        ),
      createdAt:
        Config.resolver(reviewRequestRemovedEvent, unit, dateTime, dateTime),
      id: Config.resolver(reviewRequestRemovedEvent, unit, string, string),
      pullRequest:
        Config.resolver(
          reviewRequestRemovedEvent,
          unit,
          pullRequest,
          pullRequest,
        ),
      requestedReviewer:
        Config.resolver(
          reviewRequestRemovedEvent,
          unit,
          requestedReviewer,
          option(requestedReviewer),
        ),
    };
  };
  module MilestoneConnection = {
    type t = {
      edges:
        Config.resolver(
          milestoneConnection,
          unit,
          milestoneEdge,
          option(array(option(milestoneEdge))),
        ),
      nodes:
        Config.resolver(
          milestoneConnection,
          unit,
          milestone,
          option(array(option(milestone))),
        ),
      pageInfo:
        Config.resolver(milestoneConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(milestoneConnection, unit, int, int),
    };
  };
  module ReactingUserEdge = {
    type t = {
      cursor: Config.resolver(reactingUserEdge, unit, string, string),
      node: Config.resolver(reactingUserEdge, unit, user, user),
      reactedAt: Config.resolver(reactingUserEdge, unit, dateTime, dateTime),
    };
  };
  module UnsubscribedEvent = {
    type t = {
      actor: Config.resolver(unsubscribedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(unsubscribedEvent, unit, dateTime, dateTime),
      id: Config.resolver(unsubscribedEvent, unit, string, string),
      subscribable:
        Config.resolver(unsubscribedEvent, unit, subscribable, subscribable),
    };
  };
  module PushAllowanceConnection = {
    type t = {
      edges:
        Config.resolver(
          pushAllowanceConnection,
          unit,
          pushAllowanceEdge,
          option(array(option(pushAllowanceEdge))),
        ),
      nodes:
        Config.resolver(
          pushAllowanceConnection,
          unit,
          pushAllowance,
          option(array(option(pushAllowance))),
        ),
      pageInfo:
        Config.resolver(pushAllowanceConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(pushAllowanceConnection, unit, int, int),
    };
  };
  module BranchProtectionRuleConflictConnection = {
    type t = {
      edges:
        Config.resolver(
          branchProtectionRuleConflictConnection,
          unit,
          branchProtectionRuleConflictEdge,
          option(array(option(branchProtectionRuleConflictEdge))),
        ),
      nodes:
        Config.resolver(
          branchProtectionRuleConflictConnection,
          unit,
          branchProtectionRuleConflict,
          option(array(option(branchProtectionRuleConflict))),
        ),
      pageInfo:
        Config.resolver(
          branchProtectionRuleConflictConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(
          branchProtectionRuleConflictConnection,
          unit,
          int,
          int,
        ),
    };
  };
  module UpdateProjectCardPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          updateProjectCardPayload,
          unit,
          string,
          option(string),
        ),
      projectCard:
        Config.resolver(
          updateProjectCardPayload,
          unit,
          projectCard,
          projectCard,
        ),
    };
  };
  module CodeOfConduct = {
    type t = {
      body: Config.resolver(codeOfConduct, unit, string, option(string)),
      key: Config.resolver(codeOfConduct, unit, string, string),
      name: Config.resolver(codeOfConduct, unit, string, string),
      url: Config.resolver(codeOfConduct, unit, uRI, option(uRI)),
    };
  };
  module TopicConnection = {
    type t = {
      edges:
        Config.resolver(
          topicConnection,
          unit,
          topicEdge,
          option(array(option(topicEdge))),
        ),
      nodes:
        Config.resolver(
          topicConnection,
          unit,
          topic,
          option(array(option(topic))),
        ),
      pageInfo: Config.resolver(topicConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(topicConnection, unit, int, int),
    };
  };
  module FollowingConnection = {
    type t = {
      edges:
        Config.resolver(
          followingConnection,
          unit,
          userEdge,
          option(array(option(userEdge))),
        ),
      nodes:
        Config.resolver(
          followingConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo:
        Config.resolver(followingConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(followingConnection, unit, int, int),
    };
  };
  module PullRequestConnection = {
    type t = {
      edges:
        Config.resolver(
          pullRequestConnection,
          unit,
          pullRequestEdge,
          option(array(option(pullRequestEdge))),
        ),
      nodes:
        Config.resolver(
          pullRequestConnection,
          unit,
          pullRequest,
          option(array(option(pullRequest))),
        ),
      pageInfo:
        Config.resolver(pullRequestConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(pullRequestConnection, unit, int, int),
    };
  };
  module DeclineTopicSuggestionPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          declineTopicSuggestionPayload,
          unit,
          string,
          option(string),
        ),
      topic:
        Config.resolver(declineTopicSuggestionPayload, unit, topic, topic),
    };
  };
  module Gist = {
    type t = {
      comments:
        Config.resolver(
          gist,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          gistCommentConnection,
          gistCommentConnection,
        ),
      createdAt: Config.resolver(gist, unit, dateTime, dateTime),
      description: Config.resolver(gist, unit, string, option(string)),
      id: Config.resolver(gist, unit, string, string),
      isPublic: Config.resolver(gist, unit, bool, bool),
      name: Config.resolver(gist, unit, string, string),
      owner:
        Config.resolver(
          gist,
          unit,
          repositoryOwner,
          option(repositoryOwner),
        ),
      pushedAt: Config.resolver(gist, unit, dateTime, option(dateTime)),
      stargazers:
        Config.resolver(
          gist,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(starOrder),
          },
          stargazerConnection,
          stargazerConnection,
        ),
      updatedAt: Config.resolver(gist, unit, dateTime, dateTime),
      viewerHasStarred: Config.resolver(gist, unit, bool, bool),
    };
  };
  module PublicKeyConnection = {
    type t = {
      edges:
        Config.resolver(
          publicKeyConnection,
          unit,
          publicKeyEdge,
          option(array(option(publicKeyEdge))),
        ),
      nodes:
        Config.resolver(
          publicKeyConnection,
          unit,
          publicKey,
          option(array(option(publicKey))),
        ),
      pageInfo:
        Config.resolver(publicKeyConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(publicKeyConnection, unit, int, int),
    };
  };
  module Ref = {
    type t = {
      associatedPullRequests:
        Config.resolver(
          ref,
          {
            .
            "after": option(string),
            "baseRefName": option(string),
            "before": option(string),
            "first": option(int),
            "headRefName": option(string),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(pullRequestState)),
          },
          pullRequestConnection,
          pullRequestConnection,
        ),
      id: Config.resolver(ref, unit, string, string),
      name: Config.resolver(ref, unit, string, string),
      prefix: Config.resolver(ref, unit, string, string),
      repository: Config.resolver(ref, unit, repository, repository),
      target: Config.resolver(ref, unit, gitObject, gitObject),
    };
  };
  module MilestonedEvent = {
    type t = {
      actor: Config.resolver(milestonedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(milestonedEvent, unit, dateTime, dateTime),
      id: Config.resolver(milestonedEvent, unit, string, string),
      milestoneTitle: Config.resolver(milestonedEvent, unit, string, string),
      subject:
        Config.resolver(milestonedEvent, unit, milestoneItem, milestoneItem),
    };
  };
  module ReactionEdge = {
    type t = {
      cursor: Config.resolver(reactionEdge, unit, string, string),
      node: Config.resolver(reactionEdge, unit, reaction, option(reaction)),
    };
  };
  module User = {
    type t = {
      avatarUrl: Config.resolver(user, {. "size": option(int)}, uRI, uRI),
      bio: Config.resolver(user, unit, string, option(string)),
      bioHTML: Config.resolver(user, unit, hTML, hTML),
      commitComments:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          commitCommentConnection,
          commitCommentConnection,
        ),
      company: Config.resolver(user, unit, string, option(string)),
      companyHTML: Config.resolver(user, unit, hTML, hTML),
      createdAt: Config.resolver(user, unit, dateTime, dateTime),
      databaseId: Config.resolver(user, unit, int, option(int)),
      email: Config.resolver(user, unit, string, string),
      followers:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          followerConnection,
          followerConnection,
        ),
      following:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          followingConnection,
          followingConnection,
        ),
      gist: Config.resolver(user, {. "name": string}, gist, option(gist)),
      gistComments:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          gistCommentConnection,
          gistCommentConnection,
        ),
      gists:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(gistOrder),
            "privacy": option(gistPrivacy),
          },
          gistConnection,
          gistConnection,
        ),
      id: Config.resolver(user, unit, string, string),
      isBountyHunter: Config.resolver(user, unit, bool, bool),
      isCampusExpert: Config.resolver(user, unit, bool, bool),
      isDeveloperProgramMember: Config.resolver(user, unit, bool, bool),
      isEmployee: Config.resolver(user, unit, bool, bool),
      isHireable: Config.resolver(user, unit, bool, bool),
      isSiteAdmin: Config.resolver(user, unit, bool, bool),
      isViewer: Config.resolver(user, unit, bool, bool),
      issueComments:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          issueCommentConnection,
          issueCommentConnection,
        ),
      issues:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(issueState)),
          },
          issueConnection,
          issueConnection,
        ),
      location: Config.resolver(user, unit, string, option(string)),
      login: Config.resolver(user, unit, string, string),
      name: Config.resolver(user, unit, string, option(string)),
      organization:
        Config.resolver(
          user,
          {. "login": string},
          organization,
          option(organization),
        ),
      organizations:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          organizationConnection,
          organizationConnection,
        ),
      pinnedRepositories:
        Config.resolver(
          user,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      publicKeys:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          publicKeyConnection,
          publicKeyConnection,
        ),
      pullRequests:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "baseRefName": option(string),
            "before": option(string),
            "first": option(int),
            "headRefName": option(string),
            "labels": option(array(string)),
            "last": option(int),
            "orderBy": option(issueOrder),
            "states": option(array(pullRequestState)),
          },
          pullRequestConnection,
          pullRequestConnection,
        ),
      repositories:
        Config.resolver(
          user,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isFork": option(bool),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      repositoriesContributedTo:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "contributionTypes":
              option(array(option(repositoryContributionType))),
            "first": option(int),
            "includeUserRepositories": option(bool),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      repository:
        Config.resolver(
          user,
          {. "name": string},
          repository,
          option(repository),
        ),
      resourcePath: Config.resolver(user, unit, uRI, uRI),
      starredRepositories:
        Config.resolver(
          user,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
            "orderBy": option(starOrder),
            "ownedByViewer": option(bool),
          },
          starredRepositoryConnection,
          starredRepositoryConnection,
        ),
      updatedAt: Config.resolver(user, unit, dateTime, dateTime),
      url: Config.resolver(user, unit, uRI, uRI),
      viewerCanFollow: Config.resolver(user, unit, bool, bool),
      viewerIsFollowing: Config.resolver(user, unit, bool, bool),
      watching:
        Config.resolver(
          user,
          {
            .
            "affiliations": option(array(option(repositoryAffiliation))),
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "isLocked": option(bool),
            "last": option(int),
            "orderBy": option(repositoryOrder),
            "ownerAffiliations":
              option(array(option(repositoryAffiliation))),
            "privacy": option(repositoryPrivacy),
          },
          repositoryConnection,
          repositoryConnection,
        ),
      websiteUrl: Config.resolver(user, unit, uRI, option(uRI)),
    };
  };
  module RemoveReactionPayload = {
    type t = {
      clientMutationId:
        Config.resolver(removeReactionPayload, unit, string, option(string)),
      reaction:
        Config.resolver(removeReactionPayload, unit, reaction, reaction),
      subject:
        Config.resolver(removeReactionPayload, unit, reactable, reactable),
    };
  };
  module CommitCommentThread = {
    type t = {
      comments:
        Config.resolver(
          commitCommentThread,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          commitCommentConnection,
          commitCommentConnection,
        ),
      commit: Config.resolver(commitCommentThread, unit, commit, commit),
      id: Config.resolver(commitCommentThread, unit, string, string),
      path:
        Config.resolver(commitCommentThread, unit, string, option(string)),
      position: Config.resolver(commitCommentThread, unit, int, option(int)),
      repository:
        Config.resolver(commitCommentThread, unit, repository, repository),
    };
  };
  module UpdateBranchProtectionRulePayload = {
    type t = {
      branchProtectionRule:
        Config.resolver(
          updateBranchProtectionRulePayload,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      clientMutationId:
        Config.resolver(
          updateBranchProtectionRulePayload,
          unit,
          string,
          option(string),
        ),
    };
  };
  module IssueComment = {
    type t = {
      author: Config.resolver(issueComment, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          issueComment,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(issueComment, unit, string, string),
      bodyHTML: Config.resolver(issueComment, unit, hTML, hTML),
      bodyText: Config.resolver(issueComment, unit, string, string),
      createdAt: Config.resolver(issueComment, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(issueComment, unit, bool, bool),
      databaseId: Config.resolver(issueComment, unit, int, option(int)),
      editor: Config.resolver(issueComment, unit, actor, option(actor)),
      id: Config.resolver(issueComment, unit, string, string),
      includesCreatedEdit: Config.resolver(issueComment, unit, bool, bool),
      issue: Config.resolver(issueComment, unit, issue, issue),
      lastEditedAt:
        Config.resolver(issueComment, unit, dateTime, option(dateTime)),
      publishedAt:
        Config.resolver(issueComment, unit, dateTime, option(dateTime)),
      pullRequest:
        Config.resolver(
          issueComment,
          unit,
          pullRequest,
          option(pullRequest),
        ),
      reactionGroups:
        Config.resolver(
          issueComment,
          unit,
          reactionGroup,
          option(array(reactionGroup)),
        ),
      reactions:
        Config.resolver(
          issueComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "content": option(reactionContent),
            "first": option(int),
            "last": option(int),
            "orderBy": option(reactionOrder),
          },
          reactionConnection,
          reactionConnection,
        ),
      repository: Config.resolver(issueComment, unit, repository, repository),
      resourcePath: Config.resolver(issueComment, unit, uRI, uRI),
      updatedAt: Config.resolver(issueComment, unit, dateTime, dateTime),
      url: Config.resolver(issueComment, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          issueComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanDelete: Config.resolver(issueComment, unit, bool, bool),
      viewerCanReact: Config.resolver(issueComment, unit, bool, bool),
      viewerCanUpdate: Config.resolver(issueComment, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          issueComment,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(issueComment, unit, bool, bool),
    };
  };
  module DemilestonedEvent = {
    type t = {
      actor: Config.resolver(demilestonedEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(demilestonedEvent, unit, dateTime, dateTime),
      id: Config.resolver(demilestonedEvent, unit, string, string),
      milestoneTitle:
        Config.resolver(demilestonedEvent, unit, string, string),
      subject:
        Config.resolver(
          demilestonedEvent,
          unit,
          milestoneItem,
          milestoneItem,
        ),
    };
  };
  module RenamedTitleEvent = {
    type t = {
      actor: Config.resolver(renamedTitleEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(renamedTitleEvent, unit, dateTime, dateTime),
      currentTitle: Config.resolver(renamedTitleEvent, unit, string, string),
      id: Config.resolver(renamedTitleEvent, unit, string, string),
      previousTitle: Config.resolver(renamedTitleEvent, unit, string, string),
      subject:
        Config.resolver(
          renamedTitleEvent,
          unit,
          renamedTitleSubject,
          renamedTitleSubject,
        ),
    };
  };
  module DeletePullRequestReviewPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          deletePullRequestReviewPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReview:
        Config.resolver(
          deletePullRequestReviewPayload,
          unit,
          pullRequestReview,
          pullRequestReview,
        ),
    };
  };
  module SearchResultItemEdge = {
    type t = {
      cursor: Config.resolver(searchResultItemEdge, unit, string, string),
      node:
        Config.resolver(
          searchResultItemEdge,
          unit,
          searchResultItem,
          option(searchResultItem),
        ),
      textMatches:
        Config.resolver(
          searchResultItemEdge,
          unit,
          textMatch,
          option(array(option(textMatch))),
        ),
    };
  };
  module ReviewDismissalAllowanceConnection = {
    type t = {
      edges:
        Config.resolver(
          reviewDismissalAllowanceConnection,
          unit,
          reviewDismissalAllowanceEdge,
          option(array(option(reviewDismissalAllowanceEdge))),
        ),
      nodes:
        Config.resolver(
          reviewDismissalAllowanceConnection,
          unit,
          reviewDismissalAllowance,
          option(array(option(reviewDismissalAllowance))),
        ),
      pageInfo:
        Config.resolver(
          reviewDismissalAllowanceConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(reviewDismissalAllowanceConnection, unit, int, int),
    };
  };
  module HeadRefRestoredEvent = {
    type t = {
      actor:
        Config.resolver(headRefRestoredEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(headRefRestoredEvent, unit, dateTime, dateTime),
      id: Config.resolver(headRefRestoredEvent, unit, string, string),
      pullRequest:
        Config.resolver(headRefRestoredEvent, unit, pullRequest, pullRequest),
    };
  };
  module RequestReviewsPayload = {
    type t = {
      clientMutationId:
        Config.resolver(requestReviewsPayload, unit, string, option(string)),
      pullRequest:
        Config.resolver(
          requestReviewsPayload,
          unit,
          pullRequest,
          pullRequest,
        ),
      requestedReviewersEdge:
        Config.resolver(requestReviewsPayload, unit, userEdge, userEdge),
    };
  };
  module TeamMemberEdge = {
    type t = {
      cursor: Config.resolver(teamMemberEdge, unit, string, string),
      memberAccessResourcePath:
        Config.resolver(teamMemberEdge, unit, uRI, uRI),
      memberAccessUrl: Config.resolver(teamMemberEdge, unit, uRI, uRI),
      node: Config.resolver(teamMemberEdge, unit, user, user),
      role:
        Config.resolver(teamMemberEdge, unit, teamMemberRole, teamMemberRole),
    };
  };
  module DeploymentEdge = {
    type t = {
      cursor: Config.resolver(deploymentEdge, unit, string, string),
      node:
        Config.resolver(
          deploymentEdge,
          unit,
          deployment,
          option(deployment),
        ),
    };
  };
  module DeleteProjectColumnPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          deleteProjectColumnPayload,
          unit,
          string,
          option(string),
        ),
      deletedColumnId:
        Config.resolver(deleteProjectColumnPayload, unit, string, string),
      project:
        Config.resolver(deleteProjectColumnPayload, unit, project, project),
    };
  };
  module AddProjectColumnPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          addProjectColumnPayload,
          unit,
          string,
          option(string),
        ),
      columnEdge:
        Config.resolver(
          addProjectColumnPayload,
          unit,
          projectColumnEdge,
          projectColumnEdge,
        ),
      project:
        Config.resolver(addProjectColumnPayload, unit, project, project),
    };
  };
  module PullRequestTimelineConnection = {
    type t = {
      edges:
        Config.resolver(
          pullRequestTimelineConnection,
          unit,
          pullRequestTimelineItemEdge,
          option(array(option(pullRequestTimelineItemEdge))),
        ),
      nodes:
        Config.resolver(
          pullRequestTimelineConnection,
          unit,
          pullRequestTimelineItem,
          option(array(option(pullRequestTimelineItem))),
        ),
      pageInfo:
        Config.resolver(
          pullRequestTimelineConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(pullRequestTimelineConnection, unit, int, int),
    };
  };
  module UserContentEdit = {
    type t = {
      createdAt: Config.resolver(userContentEdit, unit, dateTime, dateTime),
      deletedAt:
        Config.resolver(userContentEdit, unit, dateTime, option(dateTime)),
      deletedBy:
        Config.resolver(userContentEdit, unit, actor, option(actor)),
      diff: Config.resolver(userContentEdit, unit, string, option(string)),
      editedAt: Config.resolver(userContentEdit, unit, dateTime, dateTime),
      editor: Config.resolver(userContentEdit, unit, actor, option(actor)),
      id: Config.resolver(userContentEdit, unit, string, string),
      updatedAt: Config.resolver(userContentEdit, unit, dateTime, dateTime),
    };
  };
  module UnassignedEvent = {
    type t = {
      actor: Config.resolver(unassignedEvent, unit, actor, option(actor)),
      assignable:
        Config.resolver(unassignedEvent, unit, assignable, assignable),
      createdAt: Config.resolver(unassignedEvent, unit, dateTime, dateTime),
      id: Config.resolver(unassignedEvent, unit, string, string),
      user: Config.resolver(unassignedEvent, unit, user, option(user)),
    };
  };
  module PullRequestEdge = {
    type t = {
      cursor: Config.resolver(pullRequestEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestEdge,
          unit,
          pullRequest,
          option(pullRequest),
        ),
    };
  };
  module ProjectConnection = {
    type t = {
      edges:
        Config.resolver(
          projectConnection,
          unit,
          projectEdge,
          option(array(option(projectEdge))),
        ),
      nodes:
        Config.resolver(
          projectConnection,
          unit,
          project,
          option(array(option(project))),
        ),
      pageInfo: Config.resolver(projectConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(projectConnection, unit, int, int),
    };
  };
  module BaseRefChangedEvent = {
    type t = {
      actor:
        Config.resolver(baseRefChangedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(baseRefChangedEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(baseRefChangedEvent, unit, int, option(int)),
      id: Config.resolver(baseRefChangedEvent, unit, string, string),
    };
  };
  module OrganizationIdentityProvider = {
    type t = {
      digestMethod:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          uRI,
          option(uRI),
        ),
      externalIdentities:
        Config.resolver(
          organizationIdentityProvider,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          externalIdentityConnection,
          externalIdentityConnection,
        ),
      id: Config.resolver(organizationIdentityProvider, unit, string, string),
      idpCertificate:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          x509Certificate,
          option(x509Certificate),
        ),
      issuer:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          string,
          option(string),
        ),
      organization:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          organization,
          option(organization),
        ),
      signatureMethod:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          uRI,
          option(uRI),
        ),
      ssoUrl:
        Config.resolver(
          organizationIdentityProvider,
          unit,
          uRI,
          option(uRI),
        ),
    };
  };
  module HeadRefForcePushedEvent = {
    type t = {
      actor:
        Config.resolver(headRefForcePushedEvent, unit, actor, option(actor)),
      afterCommit:
        Config.resolver(
          headRefForcePushedEvent,
          unit,
          commit,
          option(commit),
        ),
      beforeCommit:
        Config.resolver(
          headRefForcePushedEvent,
          unit,
          commit,
          option(commit),
        ),
      createdAt:
        Config.resolver(headRefForcePushedEvent, unit, dateTime, dateTime),
      id: Config.resolver(headRefForcePushedEvent, unit, string, string),
      pullRequest:
        Config.resolver(
          headRefForcePushedEvent,
          unit,
          pullRequest,
          pullRequest,
        ),
      ref: Config.resolver(headRefForcePushedEvent, unit, ref, option(ref)),
    };
  };
  module DeploymentStatusEdge = {
    type t = {
      cursor: Config.resolver(deploymentStatusEdge, unit, string, string),
      node:
        Config.resolver(
          deploymentStatusEdge,
          unit,
          deploymentStatus,
          option(deploymentStatus),
        ),
    };
  };
  module RepositoryEdge = {
    type t = {
      cursor: Config.resolver(repositoryEdge, unit, string, string),
      node:
        Config.resolver(
          repositoryEdge,
          unit,
          repository,
          option(repository),
        ),
    };
  };
  module PublicKeyEdge = {
    type t = {
      cursor: Config.resolver(publicKeyEdge, unit, string, string),
      node:
        Config.resolver(publicKeyEdge, unit, publicKey, option(publicKey)),
    };
  };
  module AddStarPayload = {
    type t = {
      clientMutationId:
        Config.resolver(addStarPayload, unit, string, option(string)),
      starrable: Config.resolver(addStarPayload, unit, starrable, starrable),
    };
  };
  module DeleteProjectPayload = {
    type t = {
      clientMutationId:
        Config.resolver(deleteProjectPayload, unit, string, option(string)),
      owner:
        Config.resolver(
          deleteProjectPayload,
          unit,
          projectOwner,
          projectOwner,
        ),
    };
  };
  module Language = {
    type t = {
      color: Config.resolver(language, unit, string, option(string)),
      id: Config.resolver(language, unit, string, string),
      name: Config.resolver(language, unit, string, string),
    };
  };
  module RepositoryCollaboratorEdge = {
    type t = {
      cursor:
        Config.resolver(repositoryCollaboratorEdge, unit, string, string),
      node: Config.resolver(repositoryCollaboratorEdge, unit, user, user),
      permission:
        Config.resolver(
          repositoryCollaboratorEdge,
          unit,
          repositoryPermission,
          repositoryPermission,
        ),
    };
  };
  module Deployment = {
    type t = {
      commit: Config.resolver(deployment, unit, commit, option(commit)),
      createdAt: Config.resolver(deployment, unit, dateTime, dateTime),
      creator: Config.resolver(deployment, unit, actor, option(actor)),
      databaseId: Config.resolver(deployment, unit, int, option(int)),
      description: Config.resolver(deployment, unit, string, option(string)),
      environment: Config.resolver(deployment, unit, string, option(string)),
      id: Config.resolver(deployment, unit, string, string),
      latestStatus:
        Config.resolver(
          deployment,
          unit,
          deploymentStatus,
          option(deploymentStatus),
        ),
      payload: Config.resolver(deployment, unit, string, option(string)),
      ref: Config.resolver(deployment, unit, ref, option(ref)),
      repository: Config.resolver(deployment, unit, repository, repository),
      state:
        Config.resolver(
          deployment,
          unit,
          deploymentState,
          option(deploymentState),
        ),
      statuses:
        Config.resolver(
          deployment,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          deploymentStatusConnection,
          option(deploymentStatusConnection),
        ),
      task: Config.resolver(deployment, unit, string, option(string)),
      updatedAt: Config.resolver(deployment, unit, dateTime, dateTime),
    };
  };
  module BranchProtectionRule = {
    type t = {
      branchProtectionRuleConflicts:
        Config.resolver(
          branchProtectionRule,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          branchProtectionRuleConflictConnection,
          branchProtectionRuleConflictConnection,
        ),
      creator:
        Config.resolver(branchProtectionRule, unit, actor, option(actor)),
      databaseId:
        Config.resolver(branchProtectionRule, unit, int, option(int)),
      dismissesStaleReviews:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      id: Config.resolver(branchProtectionRule, unit, string, string),
      isAdminEnforced:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      matchingRefs:
        Config.resolver(
          branchProtectionRule,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          refConnection,
          refConnection,
        ),
      pattern: Config.resolver(branchProtectionRule, unit, string, string),
      pushAllowances:
        Config.resolver(
          branchProtectionRule,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          pushAllowanceConnection,
          pushAllowanceConnection,
        ),
      repository:
        Config.resolver(
          branchProtectionRule,
          unit,
          repository,
          option(repository),
        ),
      requiredApprovingReviewCount:
        Config.resolver(branchProtectionRule, unit, int, option(int)),
      requiredStatusCheckContexts:
        Config.resolver(
          branchProtectionRule,
          unit,
          string,
          option(array(option(string))),
        ),
      requiresApprovingReviews:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      requiresCommitSignatures:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      requiresStatusChecks:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      requiresStrictStatusChecks:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      restrictsPushes:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      restrictsReviewDismissals:
        Config.resolver(branchProtectionRule, unit, bool, bool),
      reviewDismissalAllowances:
        Config.resolver(
          branchProtectionRule,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          reviewDismissalAllowanceConnection,
          reviewDismissalAllowanceConnection,
        ),
    };
  };
  module Blame = {
    type t = {
      ranges: Config.resolver(blame, unit, blameRange, array(blameRange)),
    };
  };
  module TeamRepositoryEdge = {
    type t = {
      cursor: Config.resolver(teamRepositoryEdge, unit, string, string),
      node: Config.resolver(teamRepositoryEdge, unit, repository, repository),
      permission:
        Config.resolver(
          teamRepositoryEdge,
          unit,
          repositoryPermission,
          repositoryPermission,
        ),
    };
  };
  module GistEdge = {
    type t = {
      cursor: Config.resolver(gistEdge, unit, string, string),
      node: Config.resolver(gistEdge, unit, gist, option(gist)),
    };
  };
  module UserConnection = {
    type t = {
      edges:
        Config.resolver(
          userConnection,
          unit,
          userEdge,
          option(array(option(userEdge))),
        ),
      nodes:
        Config.resolver(
          userConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo: Config.resolver(userConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(userConnection, unit, int, int),
    };
  };
  module CommitHistoryConnection = {
    type t = {
      edges:
        Config.resolver(
          commitHistoryConnection,
          unit,
          commitEdge,
          option(array(option(commitEdge))),
        ),
      nodes:
        Config.resolver(
          commitHistoryConnection,
          unit,
          commit,
          option(array(option(commit))),
        ),
      pageInfo:
        Config.resolver(commitHistoryConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(commitHistoryConnection, unit, int, int),
    };
  };
  module TeamEdge = {
    type t = {
      cursor: Config.resolver(teamEdge, unit, string, string),
      node: Config.resolver(teamEdge, unit, team, option(team)),
    };
  };
  module TeamRepositoryConnection = {
    type t = {
      edges:
        Config.resolver(
          teamRepositoryConnection,
          unit,
          teamRepositoryEdge,
          option(array(option(teamRepositoryEdge))),
        ),
      nodes:
        Config.resolver(
          teamRepositoryConnection,
          unit,
          repository,
          option(array(option(repository))),
        ),
      pageInfo:
        Config.resolver(teamRepositoryConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(teamRepositoryConnection, unit, int, int),
    };
  };
  module CommitEdge = {
    type t = {
      cursor: Config.resolver(commitEdge, unit, string, string),
      node: Config.resolver(commitEdge, unit, commit, option(commit)),
    };
  };
  module BaseRefForcePushedEvent = {
    type t = {
      actor:
        Config.resolver(baseRefForcePushedEvent, unit, actor, option(actor)),
      afterCommit:
        Config.resolver(
          baseRefForcePushedEvent,
          unit,
          commit,
          option(commit),
        ),
      beforeCommit:
        Config.resolver(
          baseRefForcePushedEvent,
          unit,
          commit,
          option(commit),
        ),
      createdAt:
        Config.resolver(baseRefForcePushedEvent, unit, dateTime, dateTime),
      id: Config.resolver(baseRefForcePushedEvent, unit, string, string),
      pullRequest:
        Config.resolver(
          baseRefForcePushedEvent,
          unit,
          pullRequest,
          pullRequest,
        ),
      ref: Config.resolver(baseRefForcePushedEvent, unit, ref, option(ref)),
    };
  };
  module MarketplaceCategory = {
    type t = {
      description:
        Config.resolver(marketplaceCategory, unit, string, option(string)),
      howItWorks:
        Config.resolver(marketplaceCategory, unit, string, option(string)),
      id: Config.resolver(marketplaceCategory, unit, string, string),
      name: Config.resolver(marketplaceCategory, unit, string, string),
      primaryListingCount:
        Config.resolver(marketplaceCategory, unit, int, int),
      resourcePath: Config.resolver(marketplaceCategory, unit, uRI, uRI),
      secondaryListingCount:
        Config.resolver(marketplaceCategory, unit, int, int),
      slug: Config.resolver(marketplaceCategory, unit, string, string),
      url: Config.resolver(marketplaceCategory, unit, uRI, uRI),
    };
  };
  module BlameRange = {
    type t = {
      age: Config.resolver(blameRange, unit, int, int),
      commit: Config.resolver(blameRange, unit, commit, commit),
      endingLine: Config.resolver(blameRange, unit, int, int),
      startingLine: Config.resolver(blameRange, unit, int, int),
    };
  };
  module TreeEntry = {
    type t = {
      mode: Config.resolver(treeEntry, unit, int, int),
      name: Config.resolver(treeEntry, unit, string, string),
      [@bs.as "object"]
      object_:
        Config.resolver(treeEntry, unit, gitObject, option(gitObject)),
      oid: Config.resolver(treeEntry, unit, gitObjectID, gitObjectID),
      repository: Config.resolver(treeEntry, unit, repository, repository),
      [@bs.as "type"]
      type_: Config.resolver(treeEntry, unit, string, string),
    };
  };
  module CreateProjectPayload = {
    type t = {
      clientMutationId:
        Config.resolver(createProjectPayload, unit, string, option(string)),
      project: Config.resolver(createProjectPayload, unit, project, project),
    };
  };
  module LabelEdge = {
    type t = {
      cursor: Config.resolver(labelEdge, unit, string, string),
      node: Config.resolver(labelEdge, unit, label, option(label)),
    };
  };
  module PullRequestReviewCommentConnection = {
    type t = {
      edges:
        Config.resolver(
          pullRequestReviewCommentConnection,
          unit,
          pullRequestReviewCommentEdge,
          option(array(option(pullRequestReviewCommentEdge))),
        ),
      nodes:
        Config.resolver(
          pullRequestReviewCommentConnection,
          unit,
          pullRequestReviewComment,
          option(array(option(pullRequestReviewComment))),
        ),
      pageInfo:
        Config.resolver(
          pullRequestReviewCommentConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(pullRequestReviewCommentConnection, unit, int, int),
    };
  };
  module CommitCommentConnection = {
    type t = {
      edges:
        Config.resolver(
          commitCommentConnection,
          unit,
          commitCommentEdge,
          option(array(option(commitCommentEdge))),
        ),
      nodes:
        Config.resolver(
          commitCommentConnection,
          unit,
          commitComment,
          option(array(option(commitComment))),
        ),
      pageInfo:
        Config.resolver(commitCommentConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(commitCommentConnection, unit, int, int),
    };
  };
  module MarketplaceListing = {
    type t = {
      app: Config.resolver(marketplaceListing, unit, app, option(app)),
      companyUrl:
        Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      configurationResourcePath:
        Config.resolver(marketplaceListing, unit, uRI, uRI),
      configurationUrl: Config.resolver(marketplaceListing, unit, uRI, uRI),
      documentationUrl:
        Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      extendedDescription:
        Config.resolver(marketplaceListing, unit, string, option(string)),
      extendedDescriptionHTML:
        Config.resolver(marketplaceListing, unit, hTML, hTML),
      fullDescription:
        Config.resolver(marketplaceListing, unit, string, string),
      fullDescriptionHTML:
        Config.resolver(marketplaceListing, unit, hTML, hTML),
      hasApprovalBeenRequested:
        Config.resolver(marketplaceListing, unit, bool, bool),
      hasPublishedFreeTrialPlans:
        Config.resolver(marketplaceListing, unit, bool, bool),
      hasTermsOfService:
        Config.resolver(marketplaceListing, unit, bool, bool),
      howItWorks:
        Config.resolver(marketplaceListing, unit, string, option(string)),
      howItWorksHTML: Config.resolver(marketplaceListing, unit, hTML, hTML),
      id: Config.resolver(marketplaceListing, unit, string, string),
      installationUrl:
        Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      installedForViewer:
        Config.resolver(marketplaceListing, unit, bool, bool),
      isApproved: Config.resolver(marketplaceListing, unit, bool, bool),
      isDelisted: Config.resolver(marketplaceListing, unit, bool, bool),
      isDraft: Config.resolver(marketplaceListing, unit, bool, bool),
      isPaid: Config.resolver(marketplaceListing, unit, bool, bool),
      isRejected: Config.resolver(marketplaceListing, unit, bool, bool),
      logoBackgroundColor:
        Config.resolver(marketplaceListing, unit, string, string),
      logoUrl:
        Config.resolver(
          marketplaceListing,
          {. "size": option(int)},
          uRI,
          option(uRI),
        ),
      name: Config.resolver(marketplaceListing, unit, string, string),
      normalizedShortDescription:
        Config.resolver(marketplaceListing, unit, string, string),
      pricingUrl:
        Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      primaryCategory:
        Config.resolver(
          marketplaceListing,
          unit,
          marketplaceCategory,
          marketplaceCategory,
        ),
      privacyPolicyUrl: Config.resolver(marketplaceListing, unit, uRI, uRI),
      resourcePath: Config.resolver(marketplaceListing, unit, uRI, uRI),
      screenshotUrls:
        Config.resolver(
          marketplaceListing,
          unit,
          string,
          array(option(string)),
        ),
      secondaryCategory:
        Config.resolver(
          marketplaceListing,
          unit,
          marketplaceCategory,
          option(marketplaceCategory),
        ),
      shortDescription:
        Config.resolver(marketplaceListing, unit, string, string),
      slug: Config.resolver(marketplaceListing, unit, string, string),
      statusUrl: Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      supportEmail:
        Config.resolver(marketplaceListing, unit, string, option(string)),
      supportUrl: Config.resolver(marketplaceListing, unit, uRI, uRI),
      termsOfServiceUrl:
        Config.resolver(marketplaceListing, unit, uRI, option(uRI)),
      url: Config.resolver(marketplaceListing, unit, uRI, uRI),
      viewerCanAddPlans:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanApprove: Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanDelist: Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanEdit: Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanEditCategories:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanEditPlans:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanRedraft: Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanReject: Config.resolver(marketplaceListing, unit, bool, bool),
      viewerCanRequestApproval:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerHasPurchased:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerHasPurchasedForAllOrganizations:
        Config.resolver(marketplaceListing, unit, bool, bool),
      viewerIsListingAdmin:
        Config.resolver(marketplaceListing, unit, bool, bool),
    };
  };
  module RefEdge = {
    type t = {
      cursor: Config.resolver(refEdge, unit, string, string),
      node: Config.resolver(refEdge, unit, ref, option(ref)),
    };
  };
  module TopicEdge = {
    type t = {
      cursor: Config.resolver(topicEdge, unit, string, string),
      node: Config.resolver(topicEdge, unit, topic, option(topic)),
    };
  };
  module LanguageConnection = {
    type t = {
      edges:
        Config.resolver(
          languageConnection,
          unit,
          languageEdge,
          option(array(option(languageEdge))),
        ),
      nodes:
        Config.resolver(
          languageConnection,
          unit,
          language,
          option(array(option(language))),
        ),
      pageInfo: Config.resolver(languageConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(languageConnection, unit, int, int),
      totalSize: Config.resolver(languageConnection, unit, int, int),
    };
  };
  module ProjectCard = {
    type t = {
      column:
        Config.resolver(
          projectCard,
          unit,
          projectColumn,
          option(projectColumn),
        ),
      content:
        Config.resolver(
          projectCard,
          unit,
          projectCardItem,
          option(projectCardItem),
        ),
      createdAt: Config.resolver(projectCard, unit, dateTime, dateTime),
      creator: Config.resolver(projectCard, unit, actor, option(actor)),
      databaseId: Config.resolver(projectCard, unit, int, option(int)),
      id: Config.resolver(projectCard, unit, string, string),
      isArchived: Config.resolver(projectCard, unit, bool, bool),
      note: Config.resolver(projectCard, unit, string, option(string)),
      project: Config.resolver(projectCard, unit, project, project),
      resourcePath: Config.resolver(projectCard, unit, uRI, uRI),
      state:
        Config.resolver(
          projectCard,
          unit,
          projectCardState,
          option(projectCardState),
        ),
      updatedAt: Config.resolver(projectCard, unit, dateTime, dateTime),
      url: Config.resolver(projectCard, unit, uRI, uRI),
    };
  };
  module TextMatchHighlight = {
    type t = {
      beginIndice: Config.resolver(textMatchHighlight, unit, int, int),
      endIndice: Config.resolver(textMatchHighlight, unit, int, int),
      text: Config.resolver(textMatchHighlight, unit, string, string),
    };
  };
  module RepositoryInvitationEdge = {
    type t = {
      cursor: Config.resolver(repositoryInvitationEdge, unit, string, string),
      node:
        Config.resolver(
          repositoryInvitationEdge,
          unit,
          repositoryInvitation,
          option(repositoryInvitation),
        ),
    };
  };
  module OrganizationInvitationEdge = {
    type t = {
      cursor:
        Config.resolver(organizationInvitationEdge, unit, string, string),
      node:
        Config.resolver(
          organizationInvitationEdge,
          unit,
          organizationInvitation,
          option(organizationInvitation),
        ),
    };
  };
  module GistComment = {
    type t = {
      author: Config.resolver(gistComment, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          gistComment,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(gistComment, unit, string, string),
      bodyHTML: Config.resolver(gistComment, unit, hTML, hTML),
      bodyText: Config.resolver(gistComment, unit, string, string),
      createdAt: Config.resolver(gistComment, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(gistComment, unit, bool, bool),
      databaseId: Config.resolver(gistComment, unit, int, option(int)),
      editor: Config.resolver(gistComment, unit, actor, option(actor)),
      gist: Config.resolver(gistComment, unit, gist, gist),
      id: Config.resolver(gistComment, unit, string, string),
      includesCreatedEdit: Config.resolver(gistComment, unit, bool, bool),
      lastEditedAt:
        Config.resolver(gistComment, unit, dateTime, option(dateTime)),
      publishedAt:
        Config.resolver(gistComment, unit, dateTime, option(dateTime)),
      updatedAt: Config.resolver(gistComment, unit, dateTime, dateTime),
      userContentEdits:
        Config.resolver(
          gistComment,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanDelete: Config.resolver(gistComment, unit, bool, bool),
      viewerCanUpdate: Config.resolver(gistComment, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          gistComment,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(gistComment, unit, bool, bool),
    };
  };
  module AddProjectCardPayload = {
    type t = {
      cardEdge:
        Config.resolver(
          addProjectCardPayload,
          unit,
          projectCardEdge,
          projectCardEdge,
        ),
      clientMutationId:
        Config.resolver(addProjectCardPayload, unit, string, option(string)),
      projectColumn:
        Config.resolver(addProjectCardPayload, unit, project, project),
    };
  };
  module Reaction = {
    type t = {
      content:
        Config.resolver(reaction, unit, reactionContent, reactionContent),
      createdAt: Config.resolver(reaction, unit, dateTime, dateTime),
      databaseId: Config.resolver(reaction, unit, int, option(int)),
      id: Config.resolver(reaction, unit, string, string),
      reactable: Config.resolver(reaction, unit, reactable, reactable),
      user: Config.resolver(reaction, unit, user, option(user)),
    };
  };
  module CrossReferencedEvent = {
    type t = {
      actor:
        Config.resolver(crossReferencedEvent, unit, actor, option(actor)),
      createdAt:
        Config.resolver(crossReferencedEvent, unit, dateTime, dateTime),
      id: Config.resolver(crossReferencedEvent, unit, string, string),
      isCrossRepository:
        Config.resolver(crossReferencedEvent, unit, bool, bool),
      referencedAt:
        Config.resolver(crossReferencedEvent, unit, dateTime, dateTime),
      resourcePath: Config.resolver(crossReferencedEvent, unit, uRI, uRI),
      source:
        Config.resolver(
          crossReferencedEvent,
          unit,
          referencedSubject,
          referencedSubject,
        ),
      target:
        Config.resolver(
          crossReferencedEvent,
          unit,
          referencedSubject,
          referencedSubject,
        ),
      url: Config.resolver(crossReferencedEvent, unit, uRI, uRI),
      willCloseTarget:
        Config.resolver(crossReferencedEvent, unit, bool, bool),
    };
  };
  module IssueTimelineItemEdge = {
    type t = {
      cursor: Config.resolver(issueTimelineItemEdge, unit, string, string),
      node:
        Config.resolver(
          issueTimelineItemEdge,
          unit,
          issueTimelineItem,
          option(issueTimelineItem),
        ),
    };
  };
  module RefConnection = {
    type t = {
      edges:
        Config.resolver(
          refConnection,
          unit,
          refEdge,
          option(array(option(refEdge))),
        ),
      nodes:
        Config.resolver(
          refConnection,
          unit,
          ref,
          option(array(option(ref))),
        ),
      pageInfo: Config.resolver(refConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(refConnection, unit, int, int),
    };
  };
  module UpdateProjectColumnPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          updateProjectColumnPayload,
          unit,
          string,
          option(string),
        ),
      projectColumn:
        Config.resolver(
          updateProjectColumnPayload,
          unit,
          projectColumn,
          projectColumn,
        ),
    };
  };
  module AddPullRequestReviewPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          addPullRequestReviewPayload,
          unit,
          string,
          option(string),
        ),
      pullRequestReview:
        Config.resolver(
          addPullRequestReviewPayload,
          unit,
          pullRequestReview,
          pullRequestReview,
        ),
      reviewEdge:
        Config.resolver(
          addPullRequestReviewPayload,
          unit,
          pullRequestReviewEdge,
          pullRequestReviewEdge,
        ),
    };
  };
  module Tag = {
    type t = {
      abbreviatedOid: Config.resolver(tag, unit, string, string),
      commitResourcePath: Config.resolver(tag, unit, uRI, uRI),
      commitUrl: Config.resolver(tag, unit, uRI, uRI),
      id: Config.resolver(tag, unit, string, string),
      message: Config.resolver(tag, unit, string, option(string)),
      name: Config.resolver(tag, unit, string, string),
      oid: Config.resolver(tag, unit, gitObjectID, gitObjectID),
      repository: Config.resolver(tag, unit, repository, repository),
      tagger: Config.resolver(tag, unit, gitActor, option(gitActor)),
      target: Config.resolver(tag, unit, gitObject, gitObject),
    };
  };
  module IssueCommentConnection = {
    type t = {
      edges:
        Config.resolver(
          issueCommentConnection,
          unit,
          issueCommentEdge,
          option(array(option(issueCommentEdge))),
        ),
      nodes:
        Config.resolver(
          issueCommentConnection,
          unit,
          issueComment,
          option(array(option(issueComment))),
        ),
      pageInfo:
        Config.resolver(issueCommentConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(issueCommentConnection, unit, int, int),
    };
  };
  module LanguageEdge = {
    type t = {
      cursor: Config.resolver(languageEdge, unit, string, string),
      node: Config.resolver(languageEdge, unit, language, language),
      size: Config.resolver(languageEdge, unit, int, int),
    };
  };
  module StargazerConnection = {
    type t = {
      edges:
        Config.resolver(
          stargazerConnection,
          unit,
          stargazerEdge,
          option(array(option(stargazerEdge))),
        ),
      nodes:
        Config.resolver(
          stargazerConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo:
        Config.resolver(stargazerConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(stargazerConnection, unit, int, int),
    };
  };
  module SearchResultItemConnection = {
    type t = {
      codeCount: Config.resolver(searchResultItemConnection, unit, int, int),
      edges:
        Config.resolver(
          searchResultItemConnection,
          unit,
          searchResultItemEdge,
          option(array(option(searchResultItemEdge))),
        ),
      issueCount: Config.resolver(searchResultItemConnection, unit, int, int),
      nodes:
        Config.resolver(
          searchResultItemConnection,
          unit,
          searchResultItem,
          option(array(option(searchResultItem))),
        ),
      pageInfo:
        Config.resolver(searchResultItemConnection, unit, pageInfo, pageInfo),
      repositoryCount:
        Config.resolver(searchResultItemConnection, unit, int, int),
      userCount: Config.resolver(searchResultItemConnection, unit, int, int),
      wikiCount: Config.resolver(searchResultItemConnection, unit, int, int),
    };
  };
  module Tree = {
    type t = {
      abbreviatedOid: Config.resolver(tree, unit, string, string),
      commitResourcePath: Config.resolver(tree, unit, uRI, uRI),
      commitUrl: Config.resolver(tree, unit, uRI, uRI),
      entries:
        Config.resolver(tree, unit, treeEntry, option(array(treeEntry))),
      id: Config.resolver(tree, unit, string, string),
      oid: Config.resolver(tree, unit, gitObjectID, gitObjectID),
      repository: Config.resolver(tree, unit, repository, repository),
    };
  };
  module ReviewRequest = {
    type t = {
      databaseId: Config.resolver(reviewRequest, unit, int, option(int)),
      id: Config.resolver(reviewRequest, unit, string, string),
      pullRequest:
        Config.resolver(reviewRequest, unit, pullRequest, pullRequest),
      requestedReviewer:
        Config.resolver(
          reviewRequest,
          unit,
          requestedReviewer,
          option(requestedReviewer),
        ),
    };
  };
  module SuggestedReviewer = {
    type t = {
      isAuthor: Config.resolver(suggestedReviewer, unit, bool, bool),
      isCommenter: Config.resolver(suggestedReviewer, unit, bool, bool),
      reviewer: Config.resolver(suggestedReviewer, unit, user, user),
    };
  };
  module RemoveStarPayload = {
    type t = {
      clientMutationId:
        Config.resolver(removeStarPayload, unit, string, option(string)),
      starrable:
        Config.resolver(removeStarPayload, unit, starrable, starrable),
    };
  };
  module PullRequestCommitEdge = {
    type t = {
      cursor: Config.resolver(pullRequestCommitEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestCommitEdge,
          unit,
          pullRequestCommit,
          option(pullRequestCommit),
        ),
    };
  };
  module DeployKeyConnection = {
    type t = {
      edges:
        Config.resolver(
          deployKeyConnection,
          unit,
          deployKeyEdge,
          option(array(option(deployKeyEdge))),
        ),
      nodes:
        Config.resolver(
          deployKeyConnection,
          unit,
          deployKey,
          option(array(option(deployKey))),
        ),
      pageInfo:
        Config.resolver(deployKeyConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(deployKeyConnection, unit, int, int),
    };
  };
  module ReleaseAsset = {
    type t = {
      contentType: Config.resolver(releaseAsset, unit, string, string),
      createdAt: Config.resolver(releaseAsset, unit, dateTime, dateTime),
      downloadCount: Config.resolver(releaseAsset, unit, int, int),
      downloadUrl: Config.resolver(releaseAsset, unit, uRI, uRI),
      id: Config.resolver(releaseAsset, unit, string, string),
      name: Config.resolver(releaseAsset, unit, string, string),
      release: Config.resolver(releaseAsset, unit, release, option(release)),
      size: Config.resolver(releaseAsset, unit, int, int),
      updatedAt: Config.resolver(releaseAsset, unit, dateTime, dateTime),
      uploadedBy: Config.resolver(releaseAsset, unit, user, user),
      url: Config.resolver(releaseAsset, unit, uRI, uRI),
    };
  };
  module BranchProtectionRuleConnection = {
    type t = {
      edges:
        Config.resolver(
          branchProtectionRuleConnection,
          unit,
          branchProtectionRuleEdge,
          option(array(option(branchProtectionRuleEdge))),
        ),
      nodes:
        Config.resolver(
          branchProtectionRuleConnection,
          unit,
          branchProtectionRule,
          option(array(option(branchProtectionRule))),
        ),
      pageInfo:
        Config.resolver(
          branchProtectionRuleConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(branchProtectionRuleConnection, unit, int, int),
    };
  };
  module ReleaseAssetConnection = {
    type t = {
      edges:
        Config.resolver(
          releaseAssetConnection,
          unit,
          releaseAssetEdge,
          option(array(option(releaseAssetEdge))),
        ),
      nodes:
        Config.resolver(
          releaseAssetConnection,
          unit,
          releaseAsset,
          option(array(option(releaseAsset))),
        ),
      pageInfo:
        Config.resolver(releaseAssetConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(releaseAssetConnection, unit, int, int),
    };
  };
  module PublicKey = {
    type t = {
      id: Config.resolver(publicKey, unit, string, string),
      key: Config.resolver(publicKey, unit, string, string),
    };
  };
  module PullRequestReview = {
    type t = {
      author: Config.resolver(pullRequestReview, unit, actor, option(actor)),
      authorAssociation:
        Config.resolver(
          pullRequestReview,
          unit,
          commentAuthorAssociation,
          commentAuthorAssociation,
        ),
      body: Config.resolver(pullRequestReview, unit, string, string),
      bodyHTML: Config.resolver(pullRequestReview, unit, hTML, hTML),
      bodyText: Config.resolver(pullRequestReview, unit, string, string),
      comments:
        Config.resolver(
          pullRequestReview,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          pullRequestReviewCommentConnection,
          pullRequestReviewCommentConnection,
        ),
      commit:
        Config.resolver(pullRequestReview, unit, commit, option(commit)),
      createdAt: Config.resolver(pullRequestReview, unit, dateTime, dateTime),
      createdViaEmail: Config.resolver(pullRequestReview, unit, bool, bool),
      databaseId: Config.resolver(pullRequestReview, unit, int, option(int)),
      editor: Config.resolver(pullRequestReview, unit, actor, option(actor)),
      id: Config.resolver(pullRequestReview, unit, string, string),
      includesCreatedEdit:
        Config.resolver(pullRequestReview, unit, bool, bool),
      lastEditedAt:
        Config.resolver(pullRequestReview, unit, dateTime, option(dateTime)),
      onBehalfOf:
        Config.resolver(
          pullRequestReview,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          teamConnection,
          teamConnection,
        ),
      publishedAt:
        Config.resolver(pullRequestReview, unit, dateTime, option(dateTime)),
      pullRequest:
        Config.resolver(pullRequestReview, unit, pullRequest, pullRequest),
      repository:
        Config.resolver(pullRequestReview, unit, repository, repository),
      resourcePath: Config.resolver(pullRequestReview, unit, uRI, uRI),
      state:
        Config.resolver(
          pullRequestReview,
          unit,
          pullRequestReviewState,
          pullRequestReviewState,
        ),
      submittedAt:
        Config.resolver(pullRequestReview, unit, dateTime, option(dateTime)),
      updatedAt: Config.resolver(pullRequestReview, unit, dateTime, dateTime),
      url: Config.resolver(pullRequestReview, unit, uRI, uRI),
      userContentEdits:
        Config.resolver(
          pullRequestReview,
          {
            .
            "after": option(string),
            "before": option(string),
            "first": option(int),
            "last": option(int),
          },
          userContentEditConnection,
          option(userContentEditConnection),
        ),
      viewerCanDelete: Config.resolver(pullRequestReview, unit, bool, bool),
      viewerCanUpdate: Config.resolver(pullRequestReview, unit, bool, bool),
      viewerCannotUpdateReasons:
        Config.resolver(
          pullRequestReview,
          unit,
          commentCannotUpdateReason,
          array(commentCannotUpdateReason),
        ),
      viewerDidAuthor: Config.resolver(pullRequestReview, unit, bool, bool),
    };
  };
  module ProjectColumnEdge = {
    type t = {
      cursor: Config.resolver(projectColumnEdge, unit, string, string),
      node:
        Config.resolver(
          projectColumnEdge,
          unit,
          projectColumn,
          option(projectColumn),
        ),
    };
  };
  module PullRequestTimelineItemEdge = {
    type t = {
      cursor:
        Config.resolver(pullRequestTimelineItemEdge, unit, string, string),
      node:
        Config.resolver(
          pullRequestTimelineItemEdge,
          unit,
          pullRequestTimelineItem,
          option(pullRequestTimelineItem),
        ),
    };
  };
  module ProtectedBranchConnection = {
    type t = {
      edges:
        Config.resolver(
          protectedBranchConnection,
          unit,
          protectedBranchEdge,
          option(array(option(protectedBranchEdge))),
        ),
      nodes:
        Config.resolver(
          protectedBranchConnection,
          unit,
          protectedBranch,
          option(array(option(protectedBranch))),
        ),
      pageInfo:
        Config.resolver(protectedBranchConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(protectedBranchConnection, unit, int, int),
    };
  };
  module Bot = {
    type t = {
      avatarUrl: Config.resolver(bot, {. "size": option(int)}, uRI, uRI),
      createdAt: Config.resolver(bot, unit, dateTime, dateTime),
      databaseId: Config.resolver(bot, unit, int, option(int)),
      id: Config.resolver(bot, unit, string, string),
      login: Config.resolver(bot, unit, string, string),
      resourcePath: Config.resolver(bot, unit, uRI, uRI),
      updatedAt: Config.resolver(bot, unit, dateTime, dateTime),
      url: Config.resolver(bot, unit, uRI, uRI),
    };
  };
  module ExternalIdentityEdge = {
    type t = {
      cursor: Config.resolver(externalIdentityEdge, unit, string, string),
      node:
        Config.resolver(
          externalIdentityEdge,
          unit,
          externalIdentity,
          option(externalIdentity),
        ),
    };
  };
  module CommitConnection = {
    type t = {
      edges:
        Config.resolver(
          commitConnection,
          unit,
          commitEdge,
          option(array(option(commitEdge))),
        ),
      nodes:
        Config.resolver(
          commitConnection,
          unit,
          commit,
          option(array(option(commit))),
        ),
      pageInfo: Config.resolver(commitConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(commitConnection, unit, int, int),
    };
  };
  module GpgSignature = {
    type t = {
      email: Config.resolver(gpgSignature, unit, string, string),
      isValid: Config.resolver(gpgSignature, unit, bool, bool),
      keyId: Config.resolver(gpgSignature, unit, string, option(string)),
      payload: Config.resolver(gpgSignature, unit, string, string),
      signature: Config.resolver(gpgSignature, unit, string, string),
      signer: Config.resolver(gpgSignature, unit, user, option(user)),
      state:
        Config.resolver(
          gpgSignature,
          unit,
          gitSignatureState,
          gitSignatureState,
        ),
      wasSignedByGitHub: Config.resolver(gpgSignature, unit, bool, bool),
    };
  };
  module StatusContext = {
    type t = {
      commit: Config.resolver(statusContext, unit, commit, option(commit)),
      context: Config.resolver(statusContext, unit, string, string),
      createdAt: Config.resolver(statusContext, unit, dateTime, dateTime),
      creator: Config.resolver(statusContext, unit, actor, option(actor)),
      description:
        Config.resolver(statusContext, unit, string, option(string)),
      id: Config.resolver(statusContext, unit, string, string),
      state: Config.resolver(statusContext, unit, statusState, statusState),
      targetUrl: Config.resolver(statusContext, unit, uRI, option(uRI)),
    };
  };
  module ProjectColumnConnection = {
    type t = {
      edges:
        Config.resolver(
          projectColumnConnection,
          unit,
          projectColumnEdge,
          option(array(option(projectColumnEdge))),
        ),
      nodes:
        Config.resolver(
          projectColumnConnection,
          unit,
          projectColumn,
          option(array(option(projectColumn))),
        ),
      pageInfo:
        Config.resolver(projectColumnConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(projectColumnConnection, unit, int, int),
    };
  };
  module AssignedEvent = {
    type t = {
      actor: Config.resolver(assignedEvent, unit, actor, option(actor)),
      assignable:
        Config.resolver(assignedEvent, unit, assignable, assignable),
      createdAt: Config.resolver(assignedEvent, unit, dateTime, dateTime),
      id: Config.resolver(assignedEvent, unit, string, string),
      user: Config.resolver(assignedEvent, unit, user, option(user)),
    };
  };
  module CommitCommentEdge = {
    type t = {
      cursor: Config.resolver(commitCommentEdge, unit, string, string),
      node:
        Config.resolver(
          commitCommentEdge,
          unit,
          commitComment,
          option(commitComment),
        ),
    };
  };
  module ExternalIdentityConnection = {
    type t = {
      edges:
        Config.resolver(
          externalIdentityConnection,
          unit,
          externalIdentityEdge,
          option(array(option(externalIdentityEdge))),
        ),
      nodes:
        Config.resolver(
          externalIdentityConnection,
          unit,
          externalIdentity,
          option(array(option(externalIdentity))),
        ),
      pageInfo:
        Config.resolver(externalIdentityConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(externalIdentityConnection, unit, int, int),
    };
  };
  module AddPullRequestReviewCommentPayload = {
    type t = {
      clientMutationId:
        Config.resolver(
          addPullRequestReviewCommentPayload,
          unit,
          string,
          option(string),
        ),
      comment:
        Config.resolver(
          addPullRequestReviewCommentPayload,
          unit,
          pullRequestReviewComment,
          pullRequestReviewComment,
        ),
      commentEdge:
        Config.resolver(
          addPullRequestReviewCommentPayload,
          unit,
          pullRequestReviewCommentEdge,
          pullRequestReviewCommentEdge,
        ),
    };
  };
  module PullRequestReviewConnection = {
    type t = {
      edges:
        Config.resolver(
          pullRequestReviewConnection,
          unit,
          pullRequestReviewEdge,
          option(array(option(pullRequestReviewEdge))),
        ),
      nodes:
        Config.resolver(
          pullRequestReviewConnection,
          unit,
          pullRequestReview,
          option(array(option(pullRequestReview))),
        ),
      pageInfo:
        Config.resolver(
          pullRequestReviewConnection,
          unit,
          pageInfo,
          pageInfo,
        ),
      totalCount:
        Config.resolver(pullRequestReviewConnection, unit, int, int),
    };
  };
  module PullRequestCommit = {
    type t = {
      commit: Config.resolver(pullRequestCommit, unit, commit, commit),
      id: Config.resolver(pullRequestCommit, unit, string, string),
      pullRequest:
        Config.resolver(pullRequestCommit, unit, pullRequest, pullRequest),
      resourcePath: Config.resolver(pullRequestCommit, unit, uRI, uRI),
      url: Config.resolver(pullRequestCommit, unit, uRI, uRI),
    };
  };
  module ReviewRequestConnection = {
    type t = {
      edges:
        Config.resolver(
          reviewRequestConnection,
          unit,
          reviewRequestEdge,
          option(array(option(reviewRequestEdge))),
        ),
      nodes:
        Config.resolver(
          reviewRequestConnection,
          unit,
          reviewRequest,
          option(array(option(reviewRequest))),
        ),
      pageInfo:
        Config.resolver(reviewRequestConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(reviewRequestConnection, unit, int, int),
    };
  };
  module ReleaseConnection = {
    type t = {
      edges:
        Config.resolver(
          releaseConnection,
          unit,
          releaseEdge,
          option(array(option(releaseEdge))),
        ),
      nodes:
        Config.resolver(
          releaseConnection,
          unit,
          release,
          option(array(option(release))),
        ),
      pageInfo: Config.resolver(releaseConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(releaseConnection, unit, int, int),
    };
  };
  module OrganizationConnection = {
    type t = {
      edges:
        Config.resolver(
          organizationConnection,
          unit,
          organizationEdge,
          option(array(option(organizationEdge))),
        ),
      nodes:
        Config.resolver(
          organizationConnection,
          unit,
          organization,
          option(array(option(organization))),
        ),
      pageInfo:
        Config.resolver(organizationConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(organizationConnection, unit, int, int),
    };
  };
  module UserContentEditEdge = {
    type t = {
      cursor: Config.resolver(userContentEditEdge, unit, string, string),
      node:
        Config.resolver(
          userContentEditEdge,
          unit,
          userContentEdit,
          option(userContentEdit),
        ),
    };
  };
  module IssueCommentEdge = {
    type t = {
      cursor: Config.resolver(issueCommentEdge, unit, string, string),
      node:
        Config.resolver(
          issueCommentEdge,
          unit,
          issueComment,
          option(issueComment),
        ),
    };
  };
  module PageInfo = {
    type t = {
      endCursor: Config.resolver(pageInfo, unit, string, option(string)),
      hasNextPage: Config.resolver(pageInfo, unit, bool, bool),
      hasPreviousPage: Config.resolver(pageInfo, unit, bool, bool),
      startCursor: Config.resolver(pageInfo, unit, string, option(string)),
    };
  };
  module Status = {
    type t = {
      commit: Config.resolver(status, unit, commit, option(commit)),
      context:
        Config.resolver(
          status,
          {. "name": string},
          statusContext,
          option(statusContext),
        ),
      contexts:
        Config.resolver(status, unit, statusContext, array(statusContext)),
      id: Config.resolver(status, unit, string, string),
      state: Config.resolver(status, unit, statusState, statusState),
    };
  };
  module App = {
    type t = {
      createdAt: Config.resolver(app, unit, dateTime, dateTime),
      databaseId: Config.resolver(app, unit, int, option(int)),
      description: Config.resolver(app, unit, string, option(string)),
      id: Config.resolver(app, unit, string, string),
      logoBackgroundColor: Config.resolver(app, unit, string, string),
      logoUrl: Config.resolver(app, {. "size": option(int)}, uRI, uRI),
      name: Config.resolver(app, unit, string, string),
      slug: Config.resolver(app, unit, string, string),
      updatedAt: Config.resolver(app, unit, dateTime, dateTime),
      url: Config.resolver(app, unit, uRI, uRI),
    };
  };
  module LabeledEvent = {
    type t = {
      actor: Config.resolver(labeledEvent, unit, actor, option(actor)),
      createdAt: Config.resolver(labeledEvent, unit, dateTime, dateTime),
      id: Config.resolver(labeledEvent, unit, string, string),
      label: Config.resolver(labeledEvent, unit, label, label),
      labelable: Config.resolver(labeledEvent, unit, labelable, labelable),
    };
  };
  module ConvertedNoteToIssueEvent = {
    type t = {
      actor:
        Config.resolver(
          convertedNoteToIssueEvent,
          unit,
          actor,
          option(actor),
        ),
      createdAt:
        Config.resolver(convertedNoteToIssueEvent, unit, dateTime, dateTime),
      databaseId:
        Config.resolver(convertedNoteToIssueEvent, unit, int, option(int)),
      id: Config.resolver(convertedNoteToIssueEvent, unit, string, string),
    };
  };
  module ProjectEdge = {
    type t = {
      cursor: Config.resolver(projectEdge, unit, string, string),
      node: Config.resolver(projectEdge, unit, project, option(project)),
    };
  };
  module ReviewDismissalAllowance = {
    type t = {
      actor:
        Config.resolver(
          reviewDismissalAllowance,
          unit,
          reviewDismissalAllowanceActor,
          option(reviewDismissalAllowanceActor),
        ),
      branchProtectionRule:
        Config.resolver(
          reviewDismissalAllowance,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      id: Config.resolver(reviewDismissalAllowance, unit, string, string),
      protectedBranch:
        Config.resolver(
          reviewDismissalAllowance,
          unit,
          protectedBranch,
          protectedBranch,
        ),
    };
  };
  module PushAllowance = {
    type t = {
      actor:
        Config.resolver(
          pushAllowance,
          unit,
          pushAllowanceActor,
          option(pushAllowanceActor),
        ),
      branchProtectionRule:
        Config.resolver(
          pushAllowance,
          unit,
          branchProtectionRule,
          option(branchProtectionRule),
        ),
      id: Config.resolver(pushAllowance, unit, string, string),
      protectedBranch:
        Config.resolver(
          pushAllowance,
          unit,
          protectedBranch,
          protectedBranch,
        ),
    };
  };
  module GitActor = {
    type t = {
      avatarUrl:
        Config.resolver(gitActor, {. "size": option(int)}, uRI, uRI),
      date:
        Config.resolver(gitActor, unit, gitTimestamp, option(gitTimestamp)),
      email: Config.resolver(gitActor, unit, string, option(string)),
      name: Config.resolver(gitActor, unit, string, option(string)),
      user: Config.resolver(gitActor, unit, user, option(user)),
    };
  };
  module ReactingUserConnection = {
    type t = {
      edges:
        Config.resolver(
          reactingUserConnection,
          unit,
          reactingUserEdge,
          option(array(option(reactingUserEdge))),
        ),
      nodes:
        Config.resolver(
          reactingUserConnection,
          unit,
          user,
          option(array(option(user))),
        ),
      pageInfo:
        Config.resolver(reactingUserConnection, unit, pageInfo, pageInfo),
      totalCount: Config.resolver(reactingUserConnection, unit, int, int),
    };
  };
  type t = {
    referencedEvent: ReferencedEvent.t,
    mentionedEvent: MentionedEvent.t,
    reopenedEvent: ReopenedEvent.t,
    reviewDismissedEvent: ReviewDismissedEvent.t,
    pullRequestReviewCommentEdge: PullRequestReviewCommentEdge.t,
    unknownSignature: UnknownSignature.t,
    issueConnection: IssueConnection.t,
    gistCommentEdge: GistCommentEdge.t,
    pullRequestCommitConnection: PullRequestCommitConnection.t,
    subscribedEvent: SubscribedEvent.t,
    externalIdentitySamlAttributes: ExternalIdentitySamlAttributes.t,
    deployKey: DeployKey.t,
    milestone: Milestone.t,
    repositoryTopicConnection: RepositoryTopicConnection.t,
    smimeSignature: SmimeSignature.t,
    updatePullRequestReviewCommentPayload: UpdatePullRequestReviewCommentPayload.t,
    lockLockablePayload: LockLockablePayload.t,
    externalIdentityScimAttributes: ExternalIdentityScimAttributes.t,
    repositoryCollaboratorConnection: RepositoryCollaboratorConnection.t,
    deploymentConnection: DeploymentConnection.t,
    gistConnection: GistConnection.t,
    moveProjectCardPayload: MoveProjectCardPayload.t,
    pullRequestTimelineItemsEdge: PullRequestTimelineItemsEdge.t,
    textMatch: TextMatch.t,
    addCommentPayload: AddCommentPayload.t,
    gitHubMetadata: GitHubMetadata.t,
    starredRepositoryConnection: StarredRepositoryConnection.t,
    updateSubscriptionPayload: UpdateSubscriptionPayload.t,
    commentDeletedEvent: CommentDeletedEvent.t,
    teamConnection: TeamConnection.t,
    issueTimelineItemsEdge: IssueTimelineItemsEdge.t,
    topic: Topic.t,
    organizationInvitationConnection: OrganizationInvitationConnection.t,
    label: Label.t,
    reviewRequestEdge: ReviewRequestEdge.t,
    unlabeledEvent: UnlabeledEvent.t,
    starredRepositoryEdge: StarredRepositoryEdge.t,
    deploymentStatusConnection: DeploymentStatusConnection.t,
    query: Query.t,
    gistCommentConnection: GistCommentConnection.t,
    userEdge: UserEdge.t,
    licenseRule: LicenseRule.t,
    releaseEdge: ReleaseEdge.t,
    repositoryConnection: RepositoryConnection.t,
    projectCardEdge: ProjectCardEdge.t,
    organizationEdge: OrganizationEdge.t,
    reviewRequestedEvent: ReviewRequestedEvent.t,
    addedToProjectEvent: AddedToProjectEvent.t,
    releaseAssetEdge: ReleaseAssetEdge.t,
    issue: Issue.t,
    reactionConnection: ReactionConnection.t,
    issueTimelineConnection: IssueTimelineConnection.t,
    repositoryTopic: RepositoryTopic.t,
    marketplaceListingConnection: MarketplaceListingConnection.t,
    commit: Commit.t,
    followerConnection: FollowerConnection.t,
    project: Project.t,
    userContentEditConnection: UserContentEditConnection.t,
    reactionGroup: ReactionGroup.t,
    mergedEvent: MergedEvent.t,
    protectedBranch: ProtectedBranch.t,
    deployKeyEdge: DeployKeyEdge.t,
    deploymentEnvironmentChangedEvent: DeploymentEnvironmentChangedEvent.t,
    commitComment: CommitComment.t,
    protectedBranchEdge: ProtectedBranchEdge.t,
    rateLimit: RateLimit.t,
    removeOutsideCollaboratorPayload: RemoveOutsideCollaboratorPayload.t,
    closedEvent: ClosedEvent.t,
    pullRequest: PullRequest.t,
    team: Team.t,
    unlockedEvent: UnlockedEvent.t,
    externalIdentity: ExternalIdentity.t,
    updatePullRequestReviewPayload: UpdatePullRequestReviewPayload.t,
    appEdge: AppEdge.t,
    submitPullRequestReviewPayload: SubmitPullRequestReviewPayload.t,
    deploymentStatus: DeploymentStatus.t,
    dismissPullRequestReviewPayload: DismissPullRequestReviewPayload.t,
    organizationInvitation: OrganizationInvitation.t,
    pullRequestReviewComment: PullRequestReviewComment.t,
    organization: Organization.t,
    blob: Blob.t,
    createBranchProtectionRulePayload: CreateBranchProtectionRulePayload.t,
    movedColumnsInProjectEvent: MovedColumnsInProjectEvent.t,
    teamMemberConnection: TeamMemberConnection.t,
    marketplaceListingEdge: MarketplaceListingEdge.t,
    acceptTopicSuggestionPayload: AcceptTopicSuggestionPayload.t,
    branchProtectionRuleEdge: BranchProtectionRuleEdge.t,
    moveProjectColumnPayload: MoveProjectColumnPayload.t,
    pushAllowanceEdge: PushAllowanceEdge.t,
    lockedEvent: LockedEvent.t,
    reviewDismissalAllowanceEdge: ReviewDismissalAllowanceEdge.t,
    unlockLockablePayload: UnlockLockablePayload.t,
    deleteBranchProtectionRulePayload: DeleteBranchProtectionRulePayload.t,
    updateTopicsPayload: UpdateTopicsPayload.t,
    projectCardConnection: ProjectCardConnection.t,
    pullRequestReviewEdge: PullRequestReviewEdge.t,
    deployedEvent: DeployedEvent.t,
    stargazerEdge: StargazerEdge.t,
    release: Release.t,
    deleteProjectCardPayload: DeleteProjectCardPayload.t,
    repositoryInvitation: RepositoryInvitation.t,
    projectColumn: ProjectColumn.t,
    labelConnection: LabelConnection.t,
    milestoneEdge: MilestoneEdge.t,
    repositoryTopicEdge: RepositoryTopicEdge.t,
    updateProjectPayload: UpdateProjectPayload.t,
    repository: Repository.t,
    pullRequestReviewThread: PullRequestReviewThread.t,
    branchProtectionRuleConflict: BranchProtectionRuleConflict.t,
    addReactionPayload: AddReactionPayload.t,
    branchProtectionRuleConflictEdge: BranchProtectionRuleConflictEdge.t,
    headRefDeletedEvent: HeadRefDeletedEvent.t,
    license: License.t,
    mutation: Mutation.t,
    removedFromProjectEvent: RemovedFromProjectEvent.t,
    issueEdge: IssueEdge.t,
    reviewRequestRemovedEvent: ReviewRequestRemovedEvent.t,
    milestoneConnection: MilestoneConnection.t,
    reactingUserEdge: ReactingUserEdge.t,
    unsubscribedEvent: UnsubscribedEvent.t,
    pushAllowanceConnection: PushAllowanceConnection.t,
    branchProtectionRuleConflictConnection: BranchProtectionRuleConflictConnection.t,
    updateProjectCardPayload: UpdateProjectCardPayload.t,
    codeOfConduct: CodeOfConduct.t,
    topicConnection: TopicConnection.t,
    followingConnection: FollowingConnection.t,
    pullRequestConnection: PullRequestConnection.t,
    declineTopicSuggestionPayload: DeclineTopicSuggestionPayload.t,
    gist: Gist.t,
    publicKeyConnection: PublicKeyConnection.t,
    ref: Ref.t,
    milestonedEvent: MilestonedEvent.t,
    reactionEdge: ReactionEdge.t,
    user: User.t,
    removeReactionPayload: RemoveReactionPayload.t,
    commitCommentThread: CommitCommentThread.t,
    updateBranchProtectionRulePayload: UpdateBranchProtectionRulePayload.t,
    issueComment: IssueComment.t,
    demilestonedEvent: DemilestonedEvent.t,
    renamedTitleEvent: RenamedTitleEvent.t,
    deletePullRequestReviewPayload: DeletePullRequestReviewPayload.t,
    searchResultItemEdge: SearchResultItemEdge.t,
    reviewDismissalAllowanceConnection: ReviewDismissalAllowanceConnection.t,
    headRefRestoredEvent: HeadRefRestoredEvent.t,
    requestReviewsPayload: RequestReviewsPayload.t,
    teamMemberEdge: TeamMemberEdge.t,
    deploymentEdge: DeploymentEdge.t,
    deleteProjectColumnPayload: DeleteProjectColumnPayload.t,
    addProjectColumnPayload: AddProjectColumnPayload.t,
    pullRequestTimelineConnection: PullRequestTimelineConnection.t,
    userContentEdit: UserContentEdit.t,
    unassignedEvent: UnassignedEvent.t,
    pullRequestEdge: PullRequestEdge.t,
    projectConnection: ProjectConnection.t,
    baseRefChangedEvent: BaseRefChangedEvent.t,
    organizationIdentityProvider: OrganizationIdentityProvider.t,
    headRefForcePushedEvent: HeadRefForcePushedEvent.t,
    deploymentStatusEdge: DeploymentStatusEdge.t,
    repositoryEdge: RepositoryEdge.t,
    publicKeyEdge: PublicKeyEdge.t,
    addStarPayload: AddStarPayload.t,
    deleteProjectPayload: DeleteProjectPayload.t,
    language: Language.t,
    repositoryCollaboratorEdge: RepositoryCollaboratorEdge.t,
    deployment: Deployment.t,
    branchProtectionRule: BranchProtectionRule.t,
    blame: Blame.t,
    teamRepositoryEdge: TeamRepositoryEdge.t,
    gistEdge: GistEdge.t,
    userConnection: UserConnection.t,
    commitHistoryConnection: CommitHistoryConnection.t,
    teamEdge: TeamEdge.t,
    teamRepositoryConnection: TeamRepositoryConnection.t,
    commitEdge: CommitEdge.t,
    baseRefForcePushedEvent: BaseRefForcePushedEvent.t,
    marketplaceCategory: MarketplaceCategory.t,
    blameRange: BlameRange.t,
    treeEntry: TreeEntry.t,
    createProjectPayload: CreateProjectPayload.t,
    labelEdge: LabelEdge.t,
    pullRequestReviewCommentConnection: PullRequestReviewCommentConnection.t,
    commitCommentConnection: CommitCommentConnection.t,
    marketplaceListing: MarketplaceListing.t,
    refEdge: RefEdge.t,
    topicEdge: TopicEdge.t,
    languageConnection: LanguageConnection.t,
    projectCard: ProjectCard.t,
    textMatchHighlight: TextMatchHighlight.t,
    repositoryInvitationEdge: RepositoryInvitationEdge.t,
    organizationInvitationEdge: OrganizationInvitationEdge.t,
    gistComment: GistComment.t,
    addProjectCardPayload: AddProjectCardPayload.t,
    reaction: Reaction.t,
    crossReferencedEvent: CrossReferencedEvent.t,
    issueTimelineItemEdge: IssueTimelineItemEdge.t,
    refConnection: RefConnection.t,
    updateProjectColumnPayload: UpdateProjectColumnPayload.t,
    addPullRequestReviewPayload: AddPullRequestReviewPayload.t,
    tag: Tag.t,
    issueCommentConnection: IssueCommentConnection.t,
    languageEdge: LanguageEdge.t,
    stargazerConnection: StargazerConnection.t,
    searchResultItemConnection: SearchResultItemConnection.t,
    tree: Tree.t,
    reviewRequest: ReviewRequest.t,
    suggestedReviewer: SuggestedReviewer.t,
    removeStarPayload: RemoveStarPayload.t,
    pullRequestCommitEdge: PullRequestCommitEdge.t,
    deployKeyConnection: DeployKeyConnection.t,
    releaseAsset: ReleaseAsset.t,
    branchProtectionRuleConnection: BranchProtectionRuleConnection.t,
    releaseAssetConnection: ReleaseAssetConnection.t,
    publicKey: PublicKey.t,
    pullRequestReview: PullRequestReview.t,
    projectColumnEdge: ProjectColumnEdge.t,
    pullRequestTimelineItemEdge: PullRequestTimelineItemEdge.t,
    protectedBranchConnection: ProtectedBranchConnection.t,
    bot: Bot.t,
    externalIdentityEdge: ExternalIdentityEdge.t,
    commitConnection: CommitConnection.t,
    gpgSignature: GpgSignature.t,
    statusContext: StatusContext.t,
    projectColumnConnection: ProjectColumnConnection.t,
    assignedEvent: AssignedEvent.t,
    commitCommentEdge: CommitCommentEdge.t,
    externalIdentityConnection: ExternalIdentityConnection.t,
    addPullRequestReviewCommentPayload: AddPullRequestReviewCommentPayload.t,
    pullRequestReviewConnection: PullRequestReviewConnection.t,
    pullRequestCommit: PullRequestCommit.t,
    reviewRequestConnection: ReviewRequestConnection.t,
    releaseConnection: ReleaseConnection.t,
    organizationConnection: OrganizationConnection.t,
    userContentEditEdge: UserContentEditEdge.t,
    issueCommentEdge: IssueCommentEdge.t,
    pageInfo: PageInfo.t,
    status: Status.t,
    app: App.t,
    labeledEvent: LabeledEvent.t,
    convertedNoteToIssueEvent: ConvertedNoteToIssueEvent.t,
    projectEdge: ProjectEdge.t,
    reviewDismissalAllowance: ReviewDismissalAllowance.t,
    pushAllowance: PushAllowance.t,
    gitActor: GitActor.t,
    reactingUserConnection: ReactingUserConnection.t,
  };
};
